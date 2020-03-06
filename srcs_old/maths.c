#include "head.h"
#include "maths.h"

int     base_conv(char c)
{
	if (c == PLAYER_NONE)
		return (0);
	if (c == PLAYER_ONE)
		return (1);
	if (c == PLAYER_TWO)
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

// looks for the transformation resulting in the smallest output for trinary_board and returns that value;
int     smallest_value(char *board)
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