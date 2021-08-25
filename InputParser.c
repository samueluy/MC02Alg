#include<stdio.h>
#include<string.h>
#define MAX 255

#include "Stack.c"

/*This function is used to take input from the user
	@param str - Address of a character array to store the inputs of the user. 
*/
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

/*
	This function checks the ranking of
	precedence for each operator.
	
	@param ch - operator to be checked.
	@return ranking equivalent for the operator. -1 otherwise.

*/
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
	return -1;
}

/*
	This function is used to check if 
	the character is an operator
	
	@param ch - characteer to be checked.
	return 1 if ch is an operator. 0 otherwise.
*/
int checkOperator(char ch)
{
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
		return 1;	
	else
		return 0;
}

/*
	This function is used to evaluate 
	a postfix expression.
	
	@param postfix - postfix expression represented as array of characters.
*/
void postfixEvaluation(char postfix[]){
	struct stack temp;
	int total, A, B, i;
	
	for(i=0; i<=strlen(postfix); i++ ){
		if(postfix[i] >= 48 && postfix[i] <=57){ // check if number (can use isDigit())
		push(&temp, postfix[i]-'0'); // push numerical value to stack
		}
		else if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/'){
			A = pop(&temp);
			B = pop(&temp);
			
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

/*
	This function manipulates an infix expression,
	manipulating each character in the array using 
	a stack implementation to produce a postfix expression.
	
	@param str - Infix array of characters
	@param postfix - Array of characters for storing result.
	@param n - Number of characters in str

*/
void parser(char str[],char postfix[],int n)
{
	int i = 0;
	int j = 0;
	struct stack temp;
	temp.top = -1;
	char popTemp;
	
	/*Catch the instance where the current character is*/
	do
	{
		// Open Parenthesis
		if(str[i] == '(')
			push(&temp,str[i]);
		
		//A number	
		else if(str[i] >= 48 && str[i] <=57)
		{
			postfix[j] = str[i];
			j++;
		}
		
		//To prevent Precedence comparison with '('
		else if(temp.strContent[temp.top] == '(')
		{
			if(!checkOperator(str[i]) && str[i + 1] == '=') 
			{
				postfix[j] = ' ';
				j++;
				push(&temp,str[i + 1]);
				push(&temp,' ');
				push(&temp,str[i]);
				i++;
			}
			else
			{
				postfix[j] = ' ';
				j++;		
				/*if(checkOperator(str[i])) 	
					push(&temp,' ');    // Not sure why */
				push(&temp,str[i]);
			}
		}
		
		//Closing Parenthesis
		else if(str[i] == ')')
		{
			postfix[j] = ' ';
			j++;
			while(!stackEmpty(&temp) && temp.strContent[temp.top] != '(' )			
			{
				popTemp = pop(&temp);
				postfix[j] = popTemp;
				j++;
			}
			//Pop a '(' from stack.
			pop(&temp);
		}
		
		//Current character and Stack have equal precedence
		else if(checkPrecedence(str[i]) == checkPrecedence(temp.strContent[temp.top]))
		{	
			if(checkOperator(str[i]))
			{
				postfix[j] = ' ';
				j++;
				popTemp = pop(&temp);
				
				postfix[j] = popTemp;
				j++;
				postfix[j] = ' ';					
				j++;
				push(&temp,str[i]);
			}
			else
			{
				push(&temp,' ');
				push(&temp,str[i]);
			}
		}	
		
		//Current character has precedence
		else if(checkPrecedence(str[i]) > checkPrecedence(temp.strContent[temp.top]))
		{			
		
			push(&temp,' ');
			postfix[j] = ' ';
			j++;
			push(&temp,str[i]);
		}
		
		//Stack has higher precedence.
		else if(checkPrecedence(str[i]) < checkPrecedence(temp.strContent[temp.top]))
		{
			/*While the top of the stack's has greater precedence than the current character, 
				the stack is not empty and the top is not the '(' character... Pop and add to postfix.
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

	postfix[j] = '\0';
}

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
