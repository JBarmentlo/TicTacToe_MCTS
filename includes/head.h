#ifndef HEAD_H
# define HEAD_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "maths.h"

# define PLAY_ONE			'X'
# define PLAY_TWO			'O'
# define PLAY_NONE			'.'

# define WIN          		2
# define DRAW         		1
# define LOSS         		0

# define ITERATION_PER_TURN	1

#define C_EXPLO         	1.41421356237

# define PURPLE				"\033[95m"
# define BLUE				"\033[94m"
# define GREEN				"\033[92m"
# define YELLOW				"\033[93m"
# define RED				"\033[91m"
# define RESET				"\033[0m"
# define BOLD				"\033[1m"
# define UNDERLINE			"\033[4m"



char    *init_board(void);
char    *copy_board(char *board);
void	ft_print_board(char *str);

char    check_winner(const char *board);
void    do_move_from_key(char *board, char player);
void    do_move(char *board, int pos, char player);

int     smallest_morph(char *board);
int		trinary_board(char *board, char *tranfo);
int		trinary_board_i(char *board, int morph_index);

int 	win_score_c(char winner, int turn);
int 	win_score(const char *board, int turn);
void    add_win(char winner, char* board, int depth);

int     *futures(char *board, int turns);
int		rand_move(char *board);
int		choose_move(char *board, int turn);

char	MCTS(char *board, int turn);
char	MCTS_loud(char *board, int turn);
int		MCTS_call(char *board, int turn);

int     *db(int i);
void	print_db(void);
int     count_non_zeroes_db(void);
void 	print_victory(void);
void 	print_defeat(void);

void	play_against_AI(void);
void	show_game(void);
void	learn(int n);

void 	print_state_space_info(void);

// scoring

void	score(void);
int		play_against_perfect();
void	make_perfect_db();
void	copy_db(void *db1, void *db2);
int     *db2(int i);
int		choose_move_new(char *board, int turn, int *db_ptr);
void 	reset_dbseru(int *dbseru);
int		who_wins(int *db1, int *db2);




#define is_valid_move(board, pos) board[pos] == PLAY_NONE

#endif