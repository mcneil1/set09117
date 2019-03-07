#include <stdio.h>
#include <conio.h>

#define SIZE 9
char space[SIZE] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char space2[SIZE] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

struct stack 
{
	char undoStack[SIZE];
	char top;
};

void gameBoard();
void init_stack(struct stack *);
void push(struct stack *, char item);
char *pop(struct stack *);

void main()
{
	int player = 1;
	int playerWin = 0;
	int move; 
	char mark;
	
	struct stack s;
	init_stack(&s);
	
	char *i = NULL;

	
	do
	{

		gameBoard();
		
		player = (player % 2);
		if (player == 1)
		{
			player = 1;
		}
		else 
		{
			player = 2;
		}
		
		printf("Player %d please enter a number:", player);
		scanf("%d", &move);

		
		
		if(player == 1)
		{
			mark = 'O';
		}
		else
		{
			mark = 'X';
		}
		
		
		if (move == 1 && space[0] == '1')
		{
			space[0] = mark;
			push(&s, move);
		}
		
		else if (move == 2 && space[1] == '2')
		{
			space[1] = mark;
			push(&s, move);
		}
		
		else if (move == 3 && space[2] == '3')
		{
			space[2] = mark;
			push(&s, move);
		}
		
		else if (move == 4 && space[3] == '4')
		{
			space[3] = mark;
			push(&s, move);
		}
		
		else if (move == 5 && space[4] == '5')
		{
			space[4] = mark;
			push(&s, move);
		}
		
		else if (move == 6 && space[5] == '6')
		{
			space[5] = mark;
			push(&s, move);
		}
			
		else if (move == 7 && space[6] == '7')
		{
			space[6] = mark;
			push(&s, move);
		}
		
		else if (move == 8 && space[7] == '8')
		{
			space[7] = mark;
			push(&s, move);
		}
			
		else if (move == 9 && space[8] == '9')
		{
			space[8] = mark;
			push(&s, move);
		}
		
		else if (move == 0)
		{

			i = pop(&s);
			space[(*i)-1] = space2[(*i)-1];
		}
			
		else
		{
			printf("Invalid move, try again");
			player--;
			getch();
		}
		
		playerWin = win();
		
		player++;
		
	} while(playerWin == 0);
	gameBoard();
	
	if(playerWin == 1)
		printf("\aCongratulations Player %d, you win!", --player);
	
    else if(playerWin == 2)
		printf("\aIt's a draw!");
	
}

void init_stack(struct stack *s)
{
	s->top = -1;
}

void push(struct stack *s, char item)
{
	if(s->top == SIZE-1)
	{
		printf("Stack is full. Couldn't push '%d' onto stack\n", item);
		return;
	}
	s->top++;
	s->undoStack[s->top] = item;
}

char *pop(struct stack *s)
{
	char *data;
	if(s->top == -1)
	{
		printf("there are no moves to undo\n");
		return NULL;
	}
	
	data = &s->undoStack[s->top];
	s->top--;
	return data;
}

int win()
{


	if(space[0] == space[1] && space[1] == space[2])
		return 1;
	
	else if(space[3] == space[4] && space[4] == space[5])
		return 1;
	
	else if(space[6] == space[7] && space[7] == space[8])
		return 1;
	
	else if(space[0] == space[3] && space[3] == space[6])
		return 1;
	
	else if(space[1] == space[4] && space[4] == space[7])
		return 1;
	
	else if(space[2] == space[5] && space[5] == space[9])
		return 1;
	
	else if(space[0] == space[4] && space[4] == space[8])
		return 1;
	
	else if(space[2] == space[4] && space[4] == space[6])
		return 1;
	
	else if (space[0] != '1' && space[1] != '2' && space[2] != '3' && space[3] != '4' && space[4] != '5' && space[5] != '6' && space[6] != '7' && space[7] != '8' && space[8] != '9')
		return 2;

	else 
		return 0;
			
}

void gameBoard()
{
	system("cls");
	
	printf("\n        Noughts and Crosses\n");
	printf("Player 1 = 'O'   |   Player 2 = 'X'\n\n");
	
	printf("           -------------\n");
	printf("           | %c | %c | %c |\n", space[0], space[1], space[2]);
	printf("           |---|---|---|\n");
	printf("           | %c | %c | %c |\n", space[3], space[4], space[5]);
	printf("           |---|---|---|\n");
	printf("           | %c | %c | %c |\n", space[6], space[7], space[8]);
	printf("           -------------\n");
	
}