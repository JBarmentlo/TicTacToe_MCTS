#include "head.h"
#include "stdlib.h"


int		trinary_board(char *board, char *transformation)
{
	int		result = 0;
	int		i = 0;

	while (i < 9)
	{
		result = result << 2;
		result += board[transformation[i]];
		i++;
	}
	return (result);
}

int     smallest_value(char *board, char **transfos)
{
    int result;
    int tampoun;
    int i;

    result = trinary_board(board, transfos[0]);
    i = 1;
    while (i < 8)
    {
        tampoun = trinary_board(board, transfos[i]);
        if (tampoun < result)
            result = tampoun;
        i++;
    }
    return (result);
}

char	**make_transformations_array()
{
	int		i;
	int		j;
	char	**out;
	char	*transfos[] = transformationes;

	out = (char**)malloc(8 * sizeof(char*));
	i = 0;
	while (i < 8)
	{
		out[i] = (char*)malloc(9);
		j = 0;
		while (j < 9)
		{
			out[i][j] = transfos[i][j] - '0';
			j++;
		}
		i++;
	}
	return (out);
}

void	free_transformations_array(char **tab)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		free(tab[i]);
		i++;
	}
}