#include "head.h"

void print_db(void)
{
	int	ite = -1;
	while (++ite < 17141)
	{
		if (db(ite)[1])
			printf("%d= %d | %d\n", ite, db(ite)[0], db(ite)[1]);
	}
}
/*
int	main(void)
{
	char	*board;
	int		move;
	int		ite;

	ite = 4;
	while (ite--)
	{
		board = init_board();
		move = MCTS_call(board, 0);
		printf("CHOSEN_MOVE : %d\n\n\n", move);
		print_db();
		free(board);
	}
}
*/


int main(void) {
	char *board;

	int move;

	int turn;
	int ite;
	int big_it = 1;
	while (big_it <= 10)
	{
		ite = 2000;
		while (ite--)
		{
			turn = 0;
			board = init_board();
			while (turn < 9 && check_winner(board) == '.')
			{
				do_move(board, MCTS_call(board, turn), turn % 2 ? 'O' : 'X');
				turn++;
			}
			free(board);
		}
		turn = 0;
		board = init_board();
		while (turn < 9 && check_winner(board) == '.')
		{
			move = MCTS_call(board, turn);			
			printf("move: %d\n", move);
			do_move(board, move, turn % 2 ? 'O' : 'X');
			ft_print_board(board);
			turn++;
		}
		free(board);
		printf("trained for %d games\n", (big_it * 2000));
		big_it++;
	}
	while (1)
	{
		turn = 0;
		board = init_board();
		ft_print_board(board);
		while (turn < 9 && check_winner(board) == '.')
		{
			do_move_from_key(board, 'X');
			turn++;
			ft_print_board(board);
			if (turn < 9 && check_winner(board) == '.')
			{
				do_move(board, MCTS_call(board, turn), turn % 2 ? 'O' : 'X');
				ft_print_board(board);
			}
			turn++;
		}
		printf("the winner is %c\n", check_winner(board));
		free(board);
	}
	printf("\n");
  return (0);
}
