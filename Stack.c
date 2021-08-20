#include <stdio.h>

#define LEN1 255

typedef char token[LEN1 + 1];

struct stack
{
	token strContent;
	int top;
	int isEmpty;	
};

int stackEmpty(struct stack* S)
{
	if(S->top == 0)
	{
		S->isEmpty = 1;
		return 1;
	}
	else
	{
		S->isEmpty = 0;	
		return -1;
	}
}

void push(struct stack* S, char x)
{
	S->top = S->top + 1;
	S->strContent[S->top] = x;
}

char pop(struct stack* S)
{
	char x ='\0';
	if(stackEmpty(S) == -1)
		return x;
	else
	{
		S->top-=1;
		return S->strContent[(S->top) + 1];
	}
	
}

void display(struct stack S)
{
	int i;
	for(i=0;i<S.top;i++)
		printf("%c %d\n", S.strContent[i],i);
}

/*
int main()
{
	struct stack power;
	power.top = -1;
	push(&power, 'C');
	push(&power, 'H');
	push(&power, 'A');
	push(&power, 'R');
	push(&power, 'S');
	int i = 0;
	char ch = pop(&power);
	while(power.strContent[i] != '\0')	
	{
		printf("%c",power.strContent[i]);
		i++;
	}
	
//	printf("%d",power.top);
}*/
