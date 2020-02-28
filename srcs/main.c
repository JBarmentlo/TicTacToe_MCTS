#include "head.h"

int main(void) {
	char *board;

	int move;

	int turn;
	int it = 1;
	
	while (it <= 10)
	{
		learn(2000);
		show_game();
		printf("trained for %d games\n", (it * 2000));
		it++;
	}
	//printf("non zeroes: %d\n", count_non_zeroes_db());
	play_against_AI();
  return (0);
}
