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
	if(S->top == -1)
	{
		S->isEmpty = 1;
		return 1;
	}
	else
	{
		S->isEmpty = 0;	
		return 0;		//Should it be 1?
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
