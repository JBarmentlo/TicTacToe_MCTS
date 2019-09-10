#include "head.h"

void    reset_futures(int *futures)
{
    int i = 0;
    while (i < 9)
    {
        futures[i] = 0;
        i++;
    }
}

int     *futures(char *board, int turns)
{
    static int  futures[9];
    char        player;
    int         pos = 0;

    reset_futures(futures);
    player = turns % 2 ? PLAY_TWO : PLAY_ONE;
    while (pos < 9)
    {
        if (is_valid_move(board, pos))
        {
            do_move(board, pos, player);
            futures[pos] = smallest_value(board);
            board[pos] = '.';
        }
        pos++;
    }
    return (futures);
}

int     rand_move(char *board)
{
    int move;
    int safe;

    move = rand() % 9;
    safe = 100000;
    while (board[move] != '.')
    {
        move = rand() % 9;
        safe--;
        if (!safe)
        {
            printf("Infinite loop in rand_move. board: %.9s", board);
            return (0);
        }
    }
    return (move);
}

void    do_move(char *board, int pos, char player)
{
    board[pos] = player;
}

void     do_move_from_key(char *board, char player)
{
    int     in;
    int     pos;

	in = 0;
	while ((in < '1' - 48 || in > '9' - 48) || is_valid_move(board, pos) == 0)
    {
		in = getchar() - 48;
	    pos = (in - 1) % 3 + 3 * (2 - (in - 1) / 3);
    }
	do_move(board, pos, player);
}
