#include "head.h"

int main(void)
{
	int it = 1;
	
	while (it <= 2)
	{
		learn(2000);
		show_game();
		printf("trained for %d games\n", (it * 2000));
		it++;
	}
	printf("BATTLE PC\n");
	//play_against_AI();
	printf("BATTLE PC OVER\n");

  return (0);
}
