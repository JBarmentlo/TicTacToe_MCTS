#include "head.h"

void	learn(int n)
{
	char	*board;
	int		turn;

	while (n--)
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
}

void	play_against_AI(void)
{
	int		turn;
	char	*board;

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
}

void	show_game(void)
{
	int		turn;
	char	*board;

	board = init_board();
	turn = 0;
	while (turn < 9 && check_winner(board) == '.')
	{
		do_move(board, MCTS_call(board, turn), turn % 2 ? 'O' : 'X');
		ft_print_board(board);
		turn++;
	}
	free(board);
}
