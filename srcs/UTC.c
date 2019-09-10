#include "head.h"
#include <limits.h>

//wins_son is doubled to allow storage of 1/2 for draws
//n_dad number of visits of parent node, n_son for child node being considered;
double	UCB1(int n_dad, int n_son, int wins_son)
{
	if (n_son == 0)
		return (1000000000000.0);
	return ((double)wins_son / (2 * n_son) + C_EXPLO * (sqrt(log(n_dad) / n_son))); //n_dad should be > 0 because n_son is > 0
}

int		morph(int move, int morph_index)
{
	char *transformations[] = transformationes;
	return (transformations[morph_index][move] - 48);
}

int		choose_move(char *board, int turn)
{
	int	*future = futures(board, turn);
	int nb_now = db(smallest_value(board))[1];
	int is_leaf = 1;
	double tmp = 0;
	double res = 0;

	int next_mov = 0;
	int i = -1;
	while (!(is_valid_move(board, next_mov)))
		next_mov++;
	while (++i < 9)
	{
		if (future[i] != 0)
		{
			res = UCB1(nb_now, db(future[i])[1], db(future[i])[0]);
            if (res != 1000000000000.0)
				is_leaf = 0;
			if ((tmp < res))
			{
				tmp = res;
				next_mov = i;
			}
		}
	}
	if (is_leaf)
		return (-1);
	return (next_mov);
}

//simulates random playout and returns winner as char
char 	simulation(char *board, int turn)
{
    char    player;
    int     move;
    char     out;

    if (check_winner(board) != '.' || turn > 8)
        return(check_winner(board));
    move = rand_move(board);
    player = ((turn % 2) ? 'O' : 'X');
    do_move(board, move, player);
    out = simulation(board, turn + 1);
    do_move(board, move, PLAY_NONE);  
    return (out);
}

int		MCTS_call(char *board, int turn)
{
	char	winner;
	int		state;
	int		iterations;

	iterations = 0;
	while (iterations < ITERATION_PER_TURN)
	{
		winner = MCTS(board, turn);
		state = smallest_value(board);
		db(state)[0] += win_score_c(winner, turn);
		db(state)[1] += 1;
		iterations++;
	}
	return (choose_move(board, turn));
}

char	MCTS(char *board, int turn)
{
	if (turn > 8 || check_winner(board) != '.')
		return (check_winner(board));
	
	char	winner;
	char	player;
	int		move;
	int		state;

	player = turn % 2 ?  'O' : 'X';
	move = choose_move(board, turn);
	if (move == -1)
	{
		move = rand_move(board);
		do_move(board, move, player);
		winner = simulation(board, turn + 1);
	}
	else
	{
		do_move(board, move, player);
		winner = MCTS(board, turn + 1);
	}
	state = smallest_value(board);
	db(state)[0] += win_score_c(winner, turn);
	db(state)[1] += 1;
	do_move(board, move, PLAY_NONE);
	return (winner);
}