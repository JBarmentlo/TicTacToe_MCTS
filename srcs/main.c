#include "head.h"


int main(void) {
	char *board;

	int move;

	int turn;
	int ite;
	int big_it = 1;
	while (big_it <= 1)
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
	print_db();
	
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
