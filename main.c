#include "stdio.h"

#include "InputParser.c"


int main()
{
	struct stack input;
	input.top = -1;	
	
	char postFix[MAX];
	int i = 0;
	
	printf("Input:\n");
	getLongString(input.strContent);
	parser(input.strContent,postFix, strlen(input.strContent));
	printf("Postfix: ");
	for(i=0; i<strlen(postFix); i++)
		printf("%c", postFix[i]);

	postfixEvaluation(postFix);
	
	return 0;
}

