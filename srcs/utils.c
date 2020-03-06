#include "head.h"
#include "stdlib.h"

char    *init_board(void)
{
    char    *out;
    int     i;

    i = 0;
    out = (char*)malloc(9);

    while (i < 9)
    {
        out[i] = PLAYER_NONE;
        i++;
    }
    return (out);
}

char    check_winner(const char *board)
{
    int i;

    i = 0;
    while (i < 3)
    {
        if (board[(3 * i)] != PLAYER_NONE && board[3 * i] == board[1 + (3 * i)] && board[1 + (3 * i)] == board[2 + (3 * i)])
            return (board[3 * i]);
        i++;
    }
    i = 0;
    while (i < 3)
    {
        if (board[i] != PLAYER_NONE && board[i] == board[i + 3] && board[i + 3] == board[i + 6])
            return (board[i]);
        i++;
    }
    if (board[0] != PLAYER_NONE && board[0] == board[4] && board[4] == board[8])
        return (board[8]);
    if (board[2] != PLAYER_NONE && board[2] == board[4] && board[4] == board[6])
        return (board[6]);
    return (PLAYER_NONE);
}

int		is_valid_move(char *board, int pos)
{
	return (board[pos] == PLAYER_NONE);
}
