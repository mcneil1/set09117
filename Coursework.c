#include <stdio.h>
#include <conio.h>

#define SIZE 9
char space[SIZE] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char space2[SIZE] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

struct stack 
{
	char undoStack[SIZE];
	char redoStack[SIZE];
	char top;
};

void gameBoard();
void init_ustack(struct stack *);
void push(struct stack *, char item);
char *pop(struct stack *);
void init_rstack(struct stack *);
void redoPush(struct stack *, char item);
char *redoPop(struct stack *);
void emptyStack(struct stack *);

void main()
{
	int player = 1;
	int playerWin = 0;
	int move; 
	char mark;
	
	struct stack u;
	init_ustack(&u);
	
	struct stack r;
	init_rstack(&r);
	
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
			push(&u, move);
			emptyStack(&r);
		}
		
		else if (move == 2 && space[1] == '2')
		{
			space[1] = mark;
			push(&u, move);
			emptyStack(&r);
		}
		
		else if (move == 3 && space[2] == '3')
		{
			space[2] = mark;
			push(&u, move);
			emptyStack(&r);
		}
		
		else if (move == 4 && space[3] == '4')
		{
			space[3] = mark;
			push(&u, move);
			emptyStack(&r);
		}
		
		else if (move == 5 && space[4] == '5')
		{
			space[4] = mark;
			push(&u, move);
			emptyStack(&r);
		}
		
		else if (move == 6 && space[5] == '6')
		{
			space[5] = mark;
			push(&u, move);
			emptyStack(&r);
		}
			
		else if (move == 7 && space[6] == '7')
		{
			space[6] = mark;
			push(&u, move);
			emptyStack(&r);
		}
		
		else if (move == 8 && space[7] == '8')
		{
			space[7] = mark;
			push(&u, move);
			emptyStack(&r);
		}
			
		else if (move == 9 && space[8] == '9')
		{
			space[8] = mark;
			push(&u, move);
			emptyStack(&r);
		}
		
		else if (move == 0)
		{

			i = pop(&u);
			space[(*i)-1] = space2[(*i)-1];
			redoPush(&r, *i); 
		}
		
		else if (move == 11)
		{
			if (r.top == -1)
			{
				printf("Invalid move, no moves to redo");
				player--;
			}
			else
			{
			i = redoPop(&r);
			space[(*i)-1] = mark;
			push(&u, *i);
			}
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
		printf("\aIt'u a draw!");
	
}

void init_ustack(struct stack *u)
{
	u->top = -1;
}

void init_rstack(struct stack *r)
{
	r->top = -1;
}

void push(struct stack *u, char item)
{
	if(u->top == SIZE-1)
	{
		printf("Stack is full. Couldn't push '%d' onto stack\n", item);
		return;
	}
	u->top++;
	u->undoStack[u->top] = item;
}

void redoPush(struct stack *r, char item)
{
	r->top++;
	r->redoStack[r->top] = item;
}

char *pop(struct stack *u)
{
	char *data;
	if(u->top == -1)
	{
		printf("there are no moves to undo\n");
		return NULL;
	}
	
	data = &u->undoStack[u->top];
	u->top--;
	return data;
}

char *redoPop(struct stack *r)
{
	char *data;
	if(r->top == -1)
	{
		printf("there are no moves to redo\n");
		return NULL;
	}
	
	data = &r->redoStack[r->top];
	r->top--;
	return data;
}

void emptyStack(struct stack *r)
{
	do
	{
		redoPop(r);
	}while (r->top != -1);
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