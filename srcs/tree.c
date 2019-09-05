#include "head.h"

typedef struct		s_state 
{
	int				wins;
	int				visits;
	struct s_state	*children[9];
}					state;

state	*new_state(void)
{

}