#include <stdlib.h>
#include <stdio.h>
#include "head.h"

char  *init_board(void)
{
    char    *out;
    int     i;

    i = 0;
    out = malloc(9);

    while (i < 9)
    {
        out[i] = PLAY_NONE;
        i++;
    }
    return (out);
}

void    do_move(char *board, int pos, char player)
{
    board[pos] = player;
}

char    check_winner(const char *board)
{
    int i;

    i = 0;
    while (i < 3)
    {
        if (board[(3 * i)] != PLAY_NONE && board[3 * i] == board[1 + (3 * i)] && board[1 + (3 * i)] == board[2 + (3 * i)])
            return (board[3 * i]);
        i++;
    }
    i = 0;
    while (i < 3)
    {
        if (board[i] != PLAY_NONE && board[i] == board[i + 3] && board[i + 3] == board[i + 6])
            return (board[i]);
        i++;
    }
    if (board[0] != PLAY_NONE && board[0] == board[4] && board[4] == board[8])
        return (board[8]);
    if (board[2] != PLAY_NONE && board[2] == board[4] && board[4] == board[6])
        return (board[6]);
    return (PLAY_NONE);
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

char *copy_board(char *board)
{
    char *out;
    int  i;

    out = malloc(9);
    i = 0;
    while (i < 9)
    {
        out[i] = board[i];
        i++;
    }
    return (out);
}

void    add_win(char winner, char* board, int depth)
{
    if (winner == '.')
        db(smallest_value(board))[0] += DRAW;
    if (winner == 'X')
    {
        if (depth % 2 == 0)
            db(smallest_value(board))[0] += WIN;
        else
            db(smallest_value(board))[0] += LOSS;
    }
    else
    {
        if (depth % 2 == 0)
            db(smallest_value(board))[0] += LOSS;
        else
            db(smallest_value(board))[0] += WIN;
    }
    db(smallest_value(board))[1] += 1;
}

int *db(int i)
{
    static int db[2 * 17141];
    return (&db[2 * i]);
}

int win_score(char *board)
{
    char    winner;

    winner = check_winner(board);
    if (winner == '.')
        return (DRAW);
    if (winner == 'X')
        return (WIN);
    if (winner == 'O')
        return (LOSS);
    return (0);
}

int win_score_c(char winner)
{
    if (winner == '.')
        return (DRAW);
    if (winner == 'X')
        return (WIN);
    if (winner == 'O')
        return (LOSS);
    return (0);
}