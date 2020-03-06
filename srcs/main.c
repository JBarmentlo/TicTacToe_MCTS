#include "head.h"
#include "stdio.h"

int		main()
{
	char	*board;
	char	**transformations;

	transformations = make_transformations_array();
	board = init_board();
	board[0] = PLAYER_ONE;
	board[3] = PLAYER_TWO;
	printf("sv:%d\n", smallest_value(board, transformations));


	state	*db;

	db = make_state_db(850);
}