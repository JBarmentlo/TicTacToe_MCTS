// 29
typedef struct	s_node
{
	int				smallest_value;
	char			board[9];
	unsigned int	wins;
	unsigned int	visits;
	struct s_node	*next;
}				node;
