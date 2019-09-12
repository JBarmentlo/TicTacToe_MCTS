#include <stdlib.h>
#include <stdio.h>
#include "head.h"

char    *init_board(void)
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

char    *copy_board(const char *board)
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

//  our data is stored in an array, we malloc only one but will be used as db[i][j] through macros
//  db[i][0] the win_score of state i and db[i][1] the number of visits
//  we have reduced our number of states through symetries and rotations and then applied
//  a numbering system to it giving any state a "smallest value", the smallest value we could find 
//  for a state after rotating or mirroring it. the win_score and number of visits for a given state
//  are stored at db[smallest_value]
int     *db(int i)
{
    static int db[2 * 17141];
    return (&db[2 * i]);
}

void    print_db(void)
{
	int	ite = -1;
	while (++ite < 17141)
	{
		if (db(ite)[1])
			printf("%d= %d | %d\n", ite, db(ite)[0], db(ite)[1]);
	}
}

int     count_non_zeroes_db(void)
{
    int	ite = -1;
    int count = 0;
	while (++ite < 17141)
	{
		if (db(ite)[1])
			count++;
	}
    return (count);
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

// updates win_scores. 'O' plays on odd turns hence the modulos everywhere;
void    add_win(char winner, const char* board, int depth)
{
    int smallest_val;

    smallest_val = smallest_value(board);
    if (winner == '.')
        db(smallest_val)[0] += DRAW;
    if (winner == 'X')
    {
        if (depth % 2 == 0)
            db(smallest_val)[0] += WIN;
        else
            db(smallest_val)[0] += LOSS;
    }
    else
    {
        if (depth % 2 == 0)
            db(smallest_val)[0] += LOSS;
        else
            db(smallest_val)[0] += WIN;
    }
    db(smallest_val)[1] += 1;
}

int     win_score_c(char winner, int turn)
{
    if (winner == '.')
        return (DRAW);
	if (turn % 2)
	{
		if (winner == 'O')
       		return (WIN);
	    if (winner == 'X')
    	    return (LOSS);
	}
    if (winner == 'X')
        return (WIN);
    if (winner == 'O')
        return (LOSS);
    return (0);
}