#include "head.h"
#include "maths.h"

int     base_conv(char c)
{
	if (c == PLAY_NONE)
		return (0);
	if (c == PLAY_ONE)
		return (1);
	if (c == PLAY_TWO)
		return (2);
	return (-1);
}

// assigns a number to a board considering it a ternary base number (cf base conv)
// the tranfo is a rotation or symmetry, the board is evaluated after the tranformation
// basically a base 3 atoi if that makes sense to you
int		trinary_board(char *board, char *tranfo)
{
	int		result = 0;
	int		i = -1;

	while (++i < 9)
	{
		result *= 3;
		result += base_conv(board[tranfo[i] - '0']);
	}
	return (result);
}

__device__ int	base_conv_cuda(char c) //ALWAYS INLINE
{
	if (c == PLAY_NONE)
		return (0);
	if (c == PLAY_ONE)
		return (1);
	if (c == PLAY_TWO)
		return (2);
	return (-1);
}

__global__ void	trinary_board_cuda(char *board, char *transfo, int *out)
{
	int		result = 0;
	int		i = 0;

	while (i < 9)
	{
		result *= 3;
		result += base_conv_cuda(board[transfo[(threadIdx.x * 9) + i] - '0']);
		i++;
	}
	out[threadIdx.x] = result;
}

int     smallest_value(char *board)
{
	static int mallocced = 1;
	int i;
	char *transformations[] = transformationes;
	static char *transformations_d;
	static char *board_d;
	static int	*val_d;
	static int	*val;
	int out;
//	printf("1\n");

	if (mallocced)
	{
		printf("MALLOCCING\n");
		val = (int*)malloc(8 * sizeof(int));
		cudaMalloc(&val_d, 8 * sizeof(int));
		cudaMalloc(&transformations_d, 8 * 9);
		cudaMalloc(&board_d, 9);

		i = 0;
		while (i < 8)
		{
			cudaMemcpy(&transformations_d[9 * i], transformations[i], 9, cudaMemcpyHostToDevice);	
			i++;
		}
		mallocced = 0;
	}
	cudaMemcpy(board_d, board, 9, cudaMemcpyHostToDevice);

	trinary_board_cuda<<<1,8>>>(board_d, transformations_d, val_d);
	cudaMemcpy(val, val_d, 8 * sizeof(int), cudaMemcpyDeviceToHost);

	out = val[0];
	i = 1;
	while (i < 8)
	{
		if (val[i] < out)
		{
			out = val[i];
		}
		i++;
	}
    return (out);
}

// looks for the transformation resulting in the smallest output for trinary_board and returns that value;
int     smallest_value_tmp(char *board)
{
    int result;
    int tampoun;
    int i;
    char *transformations[] = transformationes;

    result = trinary_board(board, identity);
    i = 1;
    while (i < 8)
    {
        tampoun = trinary_board(board, transformations[i]);
        if (tampoun < result)
            result = tampoun;
        i++;
    }
    return (result);
}


//will print the combination of two transformations on terminal.
void    print_rots(char *first, char *second)
{
    int i;

    i = 0;
    while (i < 9)
    {
        printf("%c",first[second[i] - 48]);
        i++;
    }
}