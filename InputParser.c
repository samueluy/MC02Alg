#include<stdio.h>
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

void parser(char str[],char postfix[],int n)
{
	int i = 0;
	struct stack temp;
	char popTemp;
	do
	{
		//If the the current character is:
		// Open Parenthesis
		if(str[i] == '(')
			push(&temp,str[i]);
		
		//A number	
		if(str[i] >= 48 && str[i] <=57)
			postfix[i] = str[i];
		
		//For operators
		else
		{
			///If symbol in stack has higgher precedence.
			if(checkPrecedence(temp.strContent[temp.top]) > checkPrecedence(str[i]))
			{
				/*loop and Pop from stack then add to postfix until '(' is seen. 
					
					push str[i] to stack.
				 */
				do{
					popTemp = pop(&temp);
					postfix[i] = popTemp;
				}while(popTemp != '(');
				//Replace '('
					push(&temp,'(');
			}
			///If closing parenthesis
			if(str[i] == ')')
			{
			/*loop and Pop from stack then add to postfix until '(' is seen. 
					pop the '(' from stack
			*/
				do{
					popTemp = pop(&temp);
					postfix[i] = popTemp;	
				}while(popTemp != '(');
			}
			else
			{
			/*If equal precedence and anything else.
				Push to stack.*/
				push(&temp,str[i]);
			}
			printf("DEBUG ME!");		
		}

		i++;		
	}while(i<n);				//(str != '\0');
	/*
		Add ol in stack sa postFix.	
		add '\0'
	*/
	do{
		popTemp = pop(&temp);
		postfix[i] = popTemp;
		i++;
	}while(popTemp != '\0');
	
	
}

int main()
{
	struct stack input;
	char postFix[MAX];
	int i = 0;
	printf("Input:\n");
	getLongString(input.strContent);
	
	while(input.strContent[i] != '\0')
		i++;
		
	parser(input.strContent,postFix,i);
	
	i = 0;
	while(postFix[i] != '\0')
	{
		printf("\n\n%c ", postFix[i]);
		i++;
	}
	
	return 0;
}
