#include "head.h"

int main(void) {
	char *board;
	int ite = 400;

    board = init_board();

	while (ite--)
	{
 	   board = init_board();
		ft_tictactoe(board, 1);
	}
    ite = 10;
    while (ite--)
	{
 	   board = init_board();
		ft_tictactoe(board, 0);
	}

	ite = -1;
	while (++ite < 17141)
	{
		if (db(ite)[1])
			printf("%d= %d | %d\n", ite, db(ite)[0], db(ite)[1]);
	}

  return (0);
}