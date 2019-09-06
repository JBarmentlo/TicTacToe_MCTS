#include "head.h"	

void ft_tictactoe(char *board, int quiet)
{
	int turn = -1;
    
	if (NB_AI == 0)
		while (check_winner(board) == PLAY_NONE && ++turn < 9)
		{
			printf("\033[3;0H");
			ft_print_board(board);
			do_move_from_key(board, (turn % 2) == 0 ? PLAY_ONE : PLAY_TWO);

		}
	else
    {
		printf("bogosse gone\n");
		//beau_gosse(board, turn, quiet);
    }
	//ft_print_board(board);
	// if (check_winner(board) == PLAY_ONE)
	// 	print_victory();
	// else if (check_winner(board) == PLAY_TWO)
	// 	print_defeat();
    if (!quiet)
	    printf("the winner is %c\n", check_winner(board));
	
}