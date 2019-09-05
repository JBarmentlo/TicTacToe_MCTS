#include "head.h"
#include "maths.h"

int			base_conv(char c)
{
	if (c == PLAY_NONE)
		return (0);
	if (c == PLAY_ONE)
		return (1);
	if (c == PLAY_TWO)
		return (2);
	return (-1);
}

int			trinary_board(char *board, char *tranfo)
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


int			trinary_board_i(char *board, int morph_index)
{
    char *transformations[] = transformationes;
	int		result = 0;
	int		i = -1;

	while (++i < 9)
	{
		result *= 3;
		result += base_conv(board[transformations[morph_index][i] - '0']);
	}
	return (result);
}

int         smallest_value(char *board)
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

int         smallest_morph(char *board)
{
    int result;
    int tampoun;
    int morph_index;
    int i;
    char *transformations[] = transformationes;

    result = trinary_board(board, identity);
    i = 1;
    morph_index = 0;
    while (i < 8)
    {
        tampoun = trinary_board(board, transformations[i]);
        if (tampoun < result)
        {
            result = tampoun;
            morph_index = i;
        }
        i++;
    }
    return (morph_index);
}

/*
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
*/
/*
while (rotation)
	while (mirror)
		while (juxtaposition)
			check_num
return (smallest)
*/

/*
XX0
XX0
00X

874961235
*/