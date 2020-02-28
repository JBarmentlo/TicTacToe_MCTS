#include "head.h"

#define	PRECISION	10
#define	NB_STEPS	50
#define	LEARN_STEP	10

void	score(void)
{
	int		j;
	int		k;
	int 	results[NB_STEPS];
	double	results_double[NB_STEPS];

	j = 0;
	while (j < PRECISION)
	{
		k = 0;
		while (k < NB_STEPS)
		{
			learn(LEARN_STEP);
			results[k] += who_wins(db(0), db2(0));
			k++;
		}
		reset_dbseru(db(0));
		printf("%d\n", j);
		j++;
	}
	
	j = 0;
	while (j < NB_STEPS)
	{
		results_double[j] = results[j] / PRECISION;
		printf("%f, ", results_double[j]);
		j++;
	}
	return;
}

void	copy_db(void *db1, void *db2)
{
	int	i;
	
	int	*d1;
	int	*d2;

	d1 = db1;
	d2 = db2;

	i = 0;
	while (i < 2 * 17141)
	{
		d2[i] = d1[i];
		i++;
		printf("%d\n", i);
	}
}

void reset_dbseru(int *dbseru)
{
	int i = 0;
	while (i < 2 * 17141)
	{
		dbseru[i] = 0;
		i++; 
	}
}
void	make_perfect_db(void)
{
	int	j;

	j = 0;
	while (j < 10)
	{
		learn(2000);
		printf("learned %d\n", j * 2000);
		j++;
	}
	copy_db(db(0), db2(0));
	printf("UYGASDIUYGASD\n");
}

int		who_wins(int *db1, int *db2)
{
	int		turn;
	char	*board;
	int		draws;

	turn = 0;
	draws = 0;
	board = init_board();

	while (turn < 9 && check_winner(board) == '.')
	{
		if (turn % 2)
		{
			do_move(board, choose_move_new(board, turn, db1), turn % 2 ? 'O' : 'X');
		}
		else
		{
			do_move(board, choose_move_new(board, turn, db2), turn % 2 ? 'O' : 'X');
		}
	}

	if (check_winner(board) == '.')	{
		draws += 1;
	}

	free(board);
	board = init_board();

	while (turn < 9 && check_winner(board) == '.')
	{
		if (turn % 2)
		{
			do_move(board, choose_move_new(board, turn, db2), turn % 2 ? 'O' : 'X');
		}
		else
		{
			do_move(board, choose_move_new(board, turn, db1), turn % 2 ? 'O' : 'X');
		}
	}
	if (check_winner(board) == '.')	{
		draws += 1;
	}
	return (draws);
}
