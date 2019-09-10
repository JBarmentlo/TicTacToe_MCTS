#ifndef HEAD_H
# define HEAD_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "maths.h"

# define NB_AI			2


# define PLAY_ONE		'X'
# define PLAY_TWO		'O'
# define PLAY_NONE		'.'

# define WIN          2
# define DRAW         1
# define LOSS         0

# define ITERATION_PER_TURN	10

#define C_EXPLO         2.41421356237

# define PURPLE			"\033[95m"
# define BLUE			"\033[94m"
# define GREEN			"\033[92m"
# define YELLOW			"\033[93m"
# define RED			"\033[91m"
# define RESET			"\033[0m"
# define BOLD			"\033[1m"
# define UNDERLINE		"\033[4m"



void	ft_print_board(char *str);
void print_db(void);
void	ft_tictactoe(char *board, int quiet);
int     *futures(char *board, int turns);
char     beau_gosse(char *board, int depth, int quiet);

char    *init_board(void);
char    check_winner(const char *board);
void    do_move_from_key(char *board, char player);
void    do_move(char *board, int pos, char player);

char    *copy_board(char *board);
void    add_win(char winner, char* board, int depth);

int         smallest_morph(char *board);
int			trinary_board(char *board, char *tranfo);
int			trinary_board_i(char *board, int morph_index);
int 		win_score_c(char winner, int turn);
int 		win_score(char *board, int turn);

int			rand_move(char *board);

int			choose_move(char *board, int turn);
char	MCTS(char *board, int turn);
char	MCTS_loud(char *board, int turn);
int		MCTS_call(char *board, int turn);



long double explo_func(char *board, int nb_now, int nb_next, int win_next);

int     *db(int i);

#define is_valid_move(board, pos) board[pos] == PLAY_NONE

void print_victory(void);
void print_defeat(void);


#endif