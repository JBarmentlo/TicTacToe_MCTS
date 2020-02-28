#include "head.h"
#include <limits.h>

//wins_son is doubled to allow storage of 1/2 for draws
//n_dad number of visits of parent node, n_son for child node being considered;
//NB ! division by two are because the scores for wins and draws are stored as 2 and 1 but should be 1 and 1/2
//our db only allows for ints so here we are
double	UCB1(int n_dad, int n_son, int wins_son)
{
	if (n_son == 0)
		return (1000000000000.0);
	return ((double)wins_son / (2 * n_son) + C_EXPLO * (sqrt(2 * log(n_dad / 2) / n_son))); //n_dad should be > 0 because n_son is > 0
}

// chooses move with highest UCB1, if leaf node returns -1 to provoke a random simulation
// unexplored child nodes are considered highest priority in our model
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

int		choose_move_new(char *board, int turn, int *db_ptr)
{
	int	*future = futures(board, turn);
	int nb_now = db_ptr[(2 * smallest_value(board)) + 1];
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
			res = UCB1(nb_now, db_ptr[2 * future[i] + 1], db_ptr[2 * future[i]]);
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

// runs the monte carlo search algorithm ITERATIONS_PER_TURN times with the current board as root state then returns a move 
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