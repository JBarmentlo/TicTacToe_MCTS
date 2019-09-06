#include "head.h"

int main(void) {
	char *board;
	int ite = 2;

    board = init_board();

	int turn = 0;
	ft_print_board(board);
	printf("moveee: %d\n", choose_move(board, turn));
	/*
	while (turn < 9)
	{
		do_move(board, choose_move(board, 0), 'X');
		ft_print_board(board);
		do_move_from_key(board, 'O');
		ft_print_board(board);
		turn++;
		turn++;
	}
*/
	while (ite--)
	{
		MCTS(board, 0);
		printf("\n");
	}
	MCTS_loud(board, 0);
	ite = -1;
	while (++ite < 17141)
	{
		if (db(ite)[1])
			printf("%d= %d | %d\n", ite, db(ite)[0], db(ite)[1]);
	}

  return (0);
}