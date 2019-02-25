#include <stdio.h>
#include <conio.h>

void newGame();

void main()
{
	newGame();
}

void newGame()
{
	system("cls");
	
	printf("\n        Noughts and Crosses\n");
	printf("Player 1 = 'O'   |   Player 2 = 'X'\n\n");
	
	printf("           -------------\n");
	printf("           | 1 | 2 | 3 |\n");
	printf("           |---|---|---|\n");
	printf("           | 4 | 5 | 6 |\n");
	printf("           |---|---|---|\n");
	printf("           | 7 | 8 | 9 |\n");
	printf("           -------------\n");
	
}