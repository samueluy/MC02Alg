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
		return 0;
	}
}

void push(struct stack* S, char x)
{
	S->strContent[S->top] = x;
	S->top = S->top + 1;
}

int pop(struct stack* S)
{
	if(stackEmpty(S))
		return -1;
	else
	{
		S->top-=1;
		return 1;
	}
	
}

void display(struct stack S)
{
	int i;
	for(i=0;i<S.top;i++)
		printf("%c %d\n", S.strContent[i],i);
}

