#include "head.h"

void ft_print_cell(char mov)
{
	if (mov == PLAY_ONE)
		printf(GREEN);
	else if (mov == PLAY_TWO)
		printf(RED);
	else if (mov == PLAY_NONE)
		printf(BLUE);
	else
	{
		printf(YELLOW);
		printf("vfeabgiyhulvafnghipouafgsdhpnjmkhafgcshjlkgarhjkcgmreahijocgihsfohiugofsduhuiogfhjkgcfdahjklgfcdhjklcgfmhjklsdmcghjkfldshjklgcfhjlgfahjhuoihmiurwcehuimprfgwophiju,qgoxf;eijqr,p.ohp,av67844ghtw6e78r46178wye6415vwyt498thw87vvrevwrevtwvretw4681retv648v5ert248654625retwvc465retw2465465ewrty1456gb1465byht1465kb1u645n1456ilnut1456ilum1465ol4561+26245rkyui98t7yw9178w9tyr1678vwytr768vtywr1786vwyt1798wyvt1789jngerxwqhuotwegrcuohpnwvtnhumopvrwgemhopuigrceqfmhoipujmhcrgeuwouhiomcpregwcgtorehmuiwpmhoitgruewmohijp,ercgwmjophk,cefmjopfgcreqwmjoipfcregoimhjfgercwmhouigrewcmhouip5gertcmwhoupj rehoupiojhgertwmoijprewtvgioujpwreghijorgewhjegoirhlaeh5754thju3457a3rsegb04268beras2678ghtera4685aergbh486+rgewb17rgwa+897grevw45614156gaerb17y89a+bner48+61aytem1486+ity4685+1uipl,6+84152p['46+58puo486+2879+yuop7184,414685+sr148thvw8+65ert17289tw714uy561i4");
	}
	printf(" %c ", mov);
}

void print_defeat(void)
{
	printf(RED);
	printf(" _______   _______   _________   _          _                     _______    _______ \n");
	printf("(  ____/  (  ___  )  \\__   __/  ( \\        ( \\        |\\     /|  (  ____ )  (  ____ \\\n");
	printf("| (       | (   ) |     ) (     | (        | (        | )   ( |  | (    )|  | (    \\/\n");
	printf("| (__     | (___) |     | |     | |        | |        | |   | |  | (____)|  | (__    \n");
	printf("|  __)    |  ___  |     | |     | |        | |        | |   | |  |     __)  |  __)   \n");
	printf("| (       | (   ) |     | |     | |        | |        | |   | |  | (\\ (     | (      \n");
	printf("| )       | )   ( |  ___) (___  | (____/\\  | (____/\\  | (___) |  | ) \\ \\__  | (____/\\\n");
	printf("|/        |/     \\|  \\_______/  (_______/  (_______/  \(_______)  |/   \\__/  (_______/\n");
	printf(RESET);
}
void print_victory(void)
{
	printf(GREEN);
	printf(" _______               _______    _______    _______    _______    _______ \n");
	printf("(  ____ \\  |\\     /|  (  ____ \\  (  ____ \\  (  ____ \\  (  ____ \\  (  ____ \\\n");
	printf("| (    \\/  | )   ( |  | (    \\/  | (    \\/  | (    \\/  | (    \\/  | (    \\/\n");
	printf("| (_____   | |   | |  | |        | |        | (__      | (_____   | (_____ \n");
	printf("(_____  )  | |   | |  | |        | |        |  __)     (_____  )  (_____  )\n");
	printf("      ) |  | |   | |  | |        | |        | (              ) |        ) |\n");
	printf("/\\____) |  | (___) |  | (____/\\  | (____/\\  | (____/\\  /\\____) |  /\\____) |\n");
	printf("\\_______)  (_______)  (_______/  (_______/  (_______/  \\_______)  \\_______)\n");
	printf(RESET);
}


void ft_print_board(char *str)
{
	int i = -1;

	printf(RESET);
	printf("\n\n\t");
	while (++i <= 8)
	{
		ft_print_cell(str[i]);
		printf(RESET);
		if ((i + 1) % 3 == 0)
		{
			if (i > 6)
				continue;
			printf("\n\t");
			printf(" - - - - - ");
			printf("\n\t");
		}
		else
			printf("|");
	}
	printf("\n\n");
}