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
    board = init_board();


	int move;

	int turn;
	int ite;
	int big_it = 1;
	while (big_it < 200)
	{
		ite = 2000;
		while (ite--)
		{
			turn = 0;
			free(board);
			board = init_board();
			while (turn < 9 && check_winner(board) == '.')
			{
				do_move(board, MCTS_call(board, turn), turn % 2 ? 'O' : 'X');
				turn++;
			}
		}
		printf("trained for %d games\n", (big_it * 2000));
		turn = 0;
		free(board);
		board = init_board();
		while (turn < 9 && check_winner(board) == '.')
		{
			if (turn % 2)
			{
				move = rand_move(board);
			}
			else
			{
				move = MCTS_call(board, turn);			
			}
			printf("move: %d\n", move);
			do_move(board, move, turn % 2 ? 'O' : 'X');
			ft_print_board(board);
			turn++;
		}
		big_it++;
	}
	//print_db();
	printf("\n");
  return (0);
}
