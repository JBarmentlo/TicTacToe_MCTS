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

int *futures(char *board, int turns)
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

//will run forever if no possible move !!!
int rand_move(char *board)
{
    int move;

    move = rand() % 9;
    while (board[move] != '.')
    {
        move = rand() % 9;
    }
    return (move);
}

int simulation(char *board, int turn)
{
    char    player;
    int     move;
    int     out;

    if (check_winner(board) != '.' || turn > 8)
        return(win_score(board));
    move = rand_move(board);
    player = ((turn % 2) ? 'O' : 'X');
    do_move(board, move, player);
    out = simulation(board, turn + 1);
    do_move(board, move, PLAY_NONE);  
    return (out);
}


/*
void    reset(double *tab)
{
    int i;

    i = 0;
    while (i < 9)
    {
        tab[i] = -1;
        i++;
    }
}
*/
// double *explore(char *board, int state, int turns, int *db)
// {
//     static double   out[9];
//     const int       *future;
//     int             i;

//     reset(out);
//     future = futures(board, turns);

//     i = 0;
//     while (i < 9)
//     {
//         if (future[i])
//         {
//             out[i] = db(future[i])[0] / db(future[i])[1] + C_EXPLO * sqrt(log(db(state)[1]) / db(future[i])[1])
//         }
//         i++;
//     }
//     return (out);
// }
