#include "head.h"

int	count_moves(char *board, char player)
{
	int	i;
	int	out;

	i = 0;
	out = 0;
	while (i < 9)
	{
		out = out + (board[i] == player);
		i++;
	}
	return (out);
}

int	is_possible(char *board)
{
	return (count_moves(board, 'X') - count_moves(board, 'O') == 1 || count_moves(board, 'X') == count_moves(board, 'O'));
}

int	next_state(char *board, int pos)
{
//	printf("pos: %d\n", pos);
	if (pos == -1)
		return (0);
	if (board[pos] == '.')
		board[pos] = 'X';
	else if (board[pos] == 'X')
		board[pos] = 'O';
	else if (board[pos] == 'O')
	{
		board[pos] = '.';
		return (next_state(board, pos - 1));
	}
	return (1);

}

int		possible_states(void)
{
	char	*board;
	int		state;
	int		count;

	count = 0;
	board = init_board();
    db(smallest_value(board))[1] += 1;
	while (next_state(board, 8))
	{
		if (is_possible(board))
		{
			state = smallest_value(board);
   			db(state)[1] += 1;
			count++;
		}
	}
	free(board);
	return (count);
}

int		cardinal_state_space(void)
{
	possible_states();
	return (count_non_zeroes_db());
}

//does not assume X starts
int	is_possible_2(char *board)
{
	return (abs(count_moves(board, 'X') - count_moves(board, 'O')) == 1 || count_moves(board, 'X') == count_moves(board, 'O'));
}

int		possible_states_2(void)
{
	char	*board;
	int		count;

	count = 0;
	board = init_board();
	while (next_state(board, 8))
	{
		if (is_possible_2(board))
			count++;
	}
	free(board);
	return (count);
}

void print_state_space_info(void)
{
	possible_states();
	printf("total states: %d\nassuming X starts: %d \nstates after reduction %d\n", possible_states_2(), possible_states(), cardinal_state_space());
}


