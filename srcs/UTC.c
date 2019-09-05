#include "head.h"
#include <limits.h>

//wins_son is doubled to allow storage of 1/2 for draws
//n_dad number of visits of parent node, n_son for child node being considered;
double	UCB1(int n_dad, int n_son, int wins_son)
{
	if (n_son == 0)
		return (1000000000000);
	return ((double)wins_son / (2 * n_son) + C_EXPLO * (sqrt(log(n_dad) / n_son))); //n_dad should be > 0 because n_son is > 0
}

int	morph(int move, int morph_index)
{
	char *transformations[] = transformationes;

	return (transformations[morph_index][move]);
}

int	choose_move(char *board, int turn)
{
	int	morph_index;
	int	*future = futures(board, turn);
	morph_index = smallest_morph(board);
	int nb_now = db(trinary_board_i(board, morph_index))[1];

	long double tmp = 0;
	long double res = 0;

	int next_mov = 0;
	int i = -1;
	while (!(is_valid_move(board, next_mov)))
		next_mov++;

	while (++i < 9)
	{
		if (future[i] != 0)
		{
			res = UCB1(nb_now, db(future[i])[1], db(future[i])[0]);
            //
			if ((tmp < res))
			{
				res = tmp;
				next_mov = i;
			}
		}
	}
	return (morph(next_mov, morph_index));
}

char beau_gosse(char *board, int depth, int quiet)
{
    char *tmp_board = NULL;
    char winner;
    char player = (depth % 2) ? PLAY_TWO : PLAY_ONE;

    if (!quiet)
        ft_print_board(board);
    if(depth > 8 || check_winner(board) != '.')
        return (check_winner(board));
    tmp_board = copy_board(board);
    int move = choose_move(board, depth);
	do_move(board, move, player);

    winner = beau_gosse(board, depth + 1, quiet);

    add_win(winner, tmp_board, depth);
    
   // if (tmp_board) 
   //     free(tmp_board);
}
