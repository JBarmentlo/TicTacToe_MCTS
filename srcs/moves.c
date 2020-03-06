#include "head.h"

//	returns an array
// array[i] = smallest_value after playing move i
// array[i] == 0 => i is not a valid move 
int     *children_smallest_values(char *board, int turns)
{
    int			futures[9];
    char        player;
    int         pos = 0;

    player = turns % 2 ? PLAYER_TWO : PLAYER_ONE;
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
