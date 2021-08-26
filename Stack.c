#include <stdio.h>

#define MAX 256

typedef char token[MAX];
typedef int arrNum[MAX];

struct stack
{
	token strContent;
	arrNum intContent;
	int top;
	int top2;
	int isEmpty;
	int flag;
};

/*
	This function checks whether the
	current stack has an entry or not.
	
	@param S - stack used to check.
*/
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
		return 0;
	}
}

/*
	Given a stack this function 
	removes and returns the last 
	inserted element in the stack.
	Following the LIFO rule.
	
	@param S - Stack to be modified	
*/
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

/*
	This function pops a value
	from the integer array
	
	@param S - Stack to be modified.
*/
int popAsInt(struct stack* S){
	return S->intContent[S->top2--];
}

/*
	This function adds a character
	to the top index of the stack implementation.

	@param S - Stack to be modified
	@param x - Character to be added.
*/
void push(struct stack* S, char x)
{
	S->top = S->top + 1;
	S->strContent[S->top] = x;
}

/*
	This function adds a value
	to the integer array.
	This accepts multiple digit numbers.
	
	@param S - Stack to be modified.
	@param val - integer to be added to the numerical contents of the stack.
*/
void pushEval(struct stack* S, int val){
	if(S->flag==1){
		int num;
		num=popAsInt(S);
		S->intContent[++S->top2]=val+10*num;
	}
	else if(S->flag==0){
		S->intContent[++S->top2]=val;
		S->flag=1;
	}
}

/*
	This function displays the contents
	of the given stack.
	
	@param S - Stack to be displayed
*/
void display(struct stack S)
{
	int i;
	for(i=0;i<S.top;i++)
		printf("%c %d\n", S.strContent[i],i);
}
