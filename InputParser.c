#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<ctype.h>

#define MAX 255

#include "Stack.c"
void
getLongString(char str[]) 
{  char ch;
   int i = 0;

   do
   {
	   scanf("%c", &ch);
	   if (ch != '\n')
	   {
	      str[i] = ch;
		  i++;
       }
	   else str[i] = '\0';
   } while (ch != '\n');
}

/*TODO: Check for Logical and equal precedence.*/
int checkPrecedence(char ch)
{
	
	//Highest to Lowest Precedence
	if(ch == '^' || ch == '!')
		return 5;
	else if(ch == '/' || ch == '*')
		return 4;
	else if(ch == '+' || ch == '-')
		return 3;
	else if(ch == '>' || ch == '<' || ch == '=')
		return 2;
	else if(ch == '&' || ch == '|')
		return 1;
}


int checkOperator(char ch)
{
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
		return 1;	
	else
		return 0;
}

void postfixEvaluation(char postfix[]){
	struct stack temp;
	int total, A, B, i,y=0;
	
	for(i=0; i<=strlen(postfix); i++ ){
		printf("\nFor i=%d", i);
		printf("\npostfix[i]: %c\n", postfix[i]);
		if(isdigit(postfix[i])){ // check if number
			printf("\npushed: %d\n", atoi(postfix));
			push(&temp, atoi(postfix)); // push numerical value to stack
		
			while(postfix[y] != ' ') // increment where to cut array
				y++;
				
			char *substr = postfix+y;
			memmove(postfix, substr, strlen(substr)+1);
			printf("\t\t%d", y);
			y=0;
		}
		
		else if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/'){
			A = pop(&temp);
			B = pop(&temp);
			
			printf("\nA:%d\nB:%d\n", A, B);
			
			switch (postfix[i])
	            {
	            case '*':
	                total = B * A;
	                break;
	
	            case '/':
	                total = B / A;
	                break;
	
	            case '+':
	                total = B + A;
	                break;
	
	            case '-':
	                total = B - A;
	                break;
	            }
	            push(&temp, total);
		}
	}
	    printf("\nCalculation: %d \n", pop(&temp));
}

void parser(char str[],char postfix[],int n)
{
	int i = 0;
	int j = 0;
	struct stack temp;
	temp.top = -1;
	char popTemp;
	do
	{
		//If the the current character is:
		// Open Parenthesis
		if(str[i] == '(')
			push(&temp,str[i]);
		
		//A number	
		else if(isdigit(str[i]))
		{
			postfix[j] = str[i];
			j++;
		}
		//To prevent Precedence comparison with '('
		else if(temp.strContent[temp.top] == '(')
		{
			postfix[j] = ' ';
			j++;		
			push(&temp,str[i]);
		}
		//If character is )
		else if(str[i] == ')')
		{
			postfix[j] = ' ';
			j++;
			///While the stack still has input, pop and add to postfix.
			while(!stackEmpty(&temp) && temp.strContent[temp.top] != '(' )			
			{
				popTemp = pop(&temp);
				postfix[j] = popTemp;
				j++;
			}
			//Pop a '(' from stack.
			pop(&temp);
		}
		//If current character has greater precedence than the one in stack.
		else if(checkPrecedence(str[i]) >= checkPrecedence(temp.strContent[temp.top]))
			push(&temp,str[i]);
		// If the one in stack has higher precedence.
		else if(checkPrecedence(str[i]) < checkPrecedence(temp.strContent[temp.top]))
		{
			/*While the top of the stack's has greater precedence than the current character, 
				the stack is not empty and the top is not the '(' character.. Pop and add to postfix.
			*/
			push(&temp,' ');
			while(checkPrecedence(temp.strContent[temp.top] >= checkPrecedence(str[i])) &&
					!stackEmpty(&temp) && temp.strContent[temp.top] != '('){
				popTemp = pop(&temp);
				postfix[j] = popTemp;
				j++;
			}
			postfix[j] = ' ';
			j++;
			//Add the operator compared against.
			push(&temp,str[i]);
		}
		i++;		
		
	}while(i<n);
	

	//While there is still something in the stack.
	while(!stackEmpty(&temp))
	{
		popTemp = pop(&temp);
		postfix[j] = popTemp;
		j++;
	}

	postfix[strlen(postfix)] = '\0';
	
}

int main()
{
	struct stack input;
	input.top = -1;	/// IMPORTANT.
	
	char postFix[MAX];
	int i = 0;
	
	printf("Input:\n");
	getLongString(input.strContent);
	parser(input.strContent,postFix, strlen(input.strContent));
	
	printf("Postfix: ");
	for(i=0; i<strlen(postFix); i++)
		printf("%c", postFix[i]);
	printf("\n");

	postfixEvaluation(postFix);
	
	return 0;
}
