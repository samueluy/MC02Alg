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
int checkPrecedence(char chStack, char chInput)
{
	//Highest Precedence
	if(chStack == '^')
		return 3;
	//Operation in stack is * or / and input is lower than it.	
	else if(chStack == '/' || chStack == '*' && chInput != '/' || chInput != '*')
		return 2;
	else if
}
int checkOperator(char ch)
{
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
		return 1;	
	else
		return 0;
}

void parser(char str[],int n)
{
	int i = 0;
	struct stack temp;
	struct stack postfix;
	
	do
	{
		//If the the current character is:
		// Open Parenthesis
		if(str[i] == '(')
			push(&temp,str[i]);
		
		//A number	
		if(str[i] >= 48 && str[i] <=57)
			push(&postfix,str[i]);
		
		//For operators
		else
		{
			///If symbol in stack has higgher precedence.
			
		}
		
		
	}while(i<n);				//(str != '\0');
}
int main()
{
	struct stack input;
	int i;
	printf("Input:\n");
	getLongString(input.strContent);
	do	
	{
			i++;
	}while(input.strContent[i] != '\0');

	printf("%c\n",47);
	return 0;
}
