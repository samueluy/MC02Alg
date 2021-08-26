#include "stdio.h"

#include "InputParser.c"


int main()
{
	struct stack input;
	input.top = -1;	
	
	char postfix[MAX];
	int ans, valid;
	
	printf("Input: ");
	getLongString(input.strContent);
	parser(input.strContent,postfix, strlen(input.strContent));
	displayPostfix(postfix);
	
	ans=postfixEvaluation(postfix, &valid);
	if(valid)
		printf("\nCalculation: %d \n", ans);
		
	return 0;
}

