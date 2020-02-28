#include "head.h"

void	score(void)
{
	int	j;
	int k;

	j = 0;
	while (j < 100)
	{
		k = 0;
		while (k < 10000)
		{
			learn(1000);
			//play_against_perfect();
		}
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
	}
}

void	make_perfect_db(void)
{
	learn(40000);
	copy_db(db(0), db2(0));
}
