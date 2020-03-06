#include "head.h"
#include "string.h"

state	*make_state_db()
{
	state	*db;
	int		i;

	db = (state*)malloc(DB_SIZE * sizeof(state));
	bzero(db, DB_SIZE * sizeof(state));
	i = 0;
	while (i < DB_SIZE)
	{
		db[i].smallest_value = -1;
		i++;
	}
	return (db);
}

// UNTESTED
// will insert new state into db so as to keep them ordered by smallest value
void	insert_into_db(state *db, int smallest_value, int win, int visit)
{
	int	i;

	i = DB_SIZE - 1;
	while (db[i].smallest_value == -1 & i >= 0)
	{
		i--;
	}
	i++;
	while (i > 0 && db[i].smallest_value > smallest_value)
	{
		db[i] = db[i - 1];
		i--;
	}
	db[i].smallest_value = smallest_value;
	db[i].visits = visit;
	db[i].wins = win;
}

void	add_to_db(int smallest_value, int win_delta, int visit_delta, state *db)
{
	int	i;

	i = 0;
	while (i < DB_SIZE)
	{
		if (db[i].smallest_value == smallest_value)
		{
			db[i].visits += visit_delta;
			db[i].wins += win_delta;
			break;
		}
		if (db[i].smallest_value == -1)
		{
			db[i].smallest_value = smallest_value;
			db[i].visits += visit_delta;
			db[i].wins += win_delta;
		}
		i++;
	}
}

void    add_win(char winner, char* board, int depth, char **transformations, state *db)
{
    int smallest_val;

    smallest_val = smallest_value(board, transformations);
    if (winner == PLAYER_NONE)
	{
		add_to_db(smallest_val, DRAW, 1, db);
	}
    if (winner == PLAYER_ONE)
    {
        if (depth % 2 == 0)
			add_to_db(smallest_val, WIN, 1, db);
        else
			add_to_db(smallest_val, LOSS, 1, db);
    }
    else
    {
        if (depth % 2 == 0)
			add_to_db(smallest_val, LOSS, 1, db);
        else
            add_to_db(smallest_val, WIN, 1, db);

    }
}