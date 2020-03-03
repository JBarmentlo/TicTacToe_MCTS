#include "head.h"
#include "stdio.h"

// notice how the print before the infinite loop does not print.
// with a \n at the end it prints.  Don't know why but its always liek this.
void	gijs_example(void)
{
	int	i;

	printf("yo");
	i = 1;
	while (i)
	{
		i = 1;
	}
}

int main(void) 
{
	make_perfect_db();
	printf("sdfsdf");
	score();

/*
	int it = 1;
	
	while (it <= 20)
	{
		learn(2000);
		show_game();
		printf("trained for %d games\n", (it * 2000));
		it++;
	}
	
	play_against_AI();
	*/
  return (0);
}
