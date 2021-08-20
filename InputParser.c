#include<stdio.h>
#include<string.h>
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
		else if(str[i] >= 48 && str[i] <=57)
		{
			postfix[j] = str[i];
			j++;
		}
		
		//For operators
		////PROBLEM IN HERE!
		else if(str[i] == ')')
		{	
			do{
				popTemp = pop(&temp);
				printf("%cs\n", popTemp);		
				if(popTemp != '(')
				{
					postfix[j] = popTemp;
					j++;
				}
			}while(popTemp != '(' && popTemp != '\0');
		}
		else if(checkPrecedence(temp.strContent[temp.top]) > checkPrecedence(str[i]))
		{
		printf("%c\t%c\n",temp.strContent[temp.top],str[i]);
			if(temp.strContent[temp.top] != '(')
			{
				/*This means the operators compared are valid. Loop through and add to postfix.*/
			}
			else	//Meaning the operator that we saw is (
				push(&temp,str[i]);
		}
		else if(checkPrecedence(temp.strContent[temp.top]) == checkPrecedence(str[i]))
		{
			push(&temp, str[i]);
		}

		i++;		
	}while(i<n);				//(str != '\0');
	/*
		Add ol in stack sa postFix.	
		add '\0'
		
		problem here too.
	*/
	postfix[strlen(postfix) - 1] = '\0';
	
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
	
	i = 0;
	while(i<strlen(postFix))
	{
		printf("%c ", postFix[i]);
		i++;
	}
	
	return 0;
}
