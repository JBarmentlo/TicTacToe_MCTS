#ifndef HEAD_H
# define HEAD_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "maths.h"

# define PLAYER_ONE			1
# define PLAYER_TWO			2
# define PLAYER_NONE		0

# define WIN          		2
# define DRAW         		1
# define LOSS         		0

# define ITERATION_PER_TURN	10

# define C_EXPLO         	1.41421356237

# define PURPLE				"\033[95m"
# define BLUE				"\033[94m"
# define GREEN				"\033[92m"
# define YELLOW				"\033[93m"
# define RED				"\033[91m"
# define RESET				"\033[0m"
# define BOLD				"\033[1m"
# define UNDERLINE			"\033[4m"

# define DB_SIZE			850

typedef struct	s_state
{
	int				smallest_value;
	unsigned int	wins;
	unsigned int	visits;
	struct s_node	*next;
	char			board[9];
}				state;

char    *init_board(void);
int     base_conv(char c);
char    check_winner(const char *board);
int		trinary_board(char *board, char *tranfo);
int     smallest_value(char *board, char **transfos);
char	**make_transformations_array();
void	free_transformations_array(char **tab);
state	*make_state_db(void);





#endif