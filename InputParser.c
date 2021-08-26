#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>

#define MAX 255

#include "Stack.c"

/*This function is used to take i(put from the user
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
	This function is used to select which switch
	case must be executed for Arithmetic,
	Relational, and logical operators.
	
	@param postfix - postfix character array
	@param *i - pointer to the current index of the for loop
	
*/


char selectOp(char postfix[MAX], int *i){
	char ch = postfix[*i];
	char nextCh = postfix[*i+1];
	
	if(ch=='>'&&nextCh=='='){
		*i+=1;
		return '1';
	}
		
	else if(ch=='<'&&nextCh=='='){
		*i+=1;
		return '2';
	}
	else if(ch=='!'&&nextCh=='='){
		*i+=1;
		return '3';
	}
	else if(ch=='='&&nextCh=='='){
		*i+=1;
		return '4';
	}
	else if(ch=='&'&&nextCh=='&'){
		*i+=1;
		return '5';
	}
	else if(ch=='|'&&nextCh=='|'){
		*i+=1;
		return '6';
	}
	else
		return postfix[*i];
}

/*
	This function is used to evaluate 
	a postfix expression.
	
	@param postfix - postfix expression represented as array of characters.
*/

int postfixEvaluation(char postfix[]){
	struct stack temp;
	int A, B, bVal,i;
	int valid=1;
	char ch;
	
	temp.top2=-1;
	temp.flag=0;
	
	for(i=0; i<=strlen(postfix)-1; i++){
		ch=postfix[i];
		if(isdigit(ch)){ // check if number
			pushEval(&temp, ch-'0'); // push numerical value to stack
		}
		else if(ch == ' ')
			temp.flag=0;
		else{
			temp.flag=0;
			bVal=0;
			B = popAsInt(&temp);
			A = popAsInt(&temp);
			ch=selectOp(postfix, &i);
			switch (ch)
	            {
	            case '+':
	                pushEval(&temp, A+B);
	                break;
	            case '-':
	                pushEval(&temp, A-B);
	                break;
	            case '*':
	                pushEval(&temp, A*B);
	                break;
	            case '/':
	            	if(B==0){
	            		printf("\nDivision by zero error!\n");
	            		valid=0;
					}
	            	else
	                	pushEval(&temp, A/B);
	                break;
	            case '%':
	            	pushEval(&temp, A%B);
	            	break;
	            case '^':
	            	pushEval(&temp, pow(A,B));
	            	break;
	            case '>':
	            	if(A>B)
	            		bVal=1;
	            	pushEval(&temp, bVal);
	            	break;
	            case '<':
	            	if(A<B)
	            		bVal=1;
	            	pushEval(&temp, bVal);
	            	break;
	            case '1':
	            	if(A>=B)
	            		bVal=1;
	            	pushEval(&temp, bVal);
	            	break;
	            case '2':
	            	if(A<=B)
	            		bVal=1;
	            	pushEval(&temp, bVal);
	            	break;
	            case '3':
	            	if(A!=B)
	            		bVal=1;
	            	pushEval(&temp, bVal);
	            	break;
				case '4':
					if(A==B)
	            		bVal=1;
	            	pushEval(&temp, bVal);
	            	break;
	            case '5':
	            	if(A&&B)
	            		bVal=1;
	            	pushEval(&temp, bVal);
	            	break;
	            case '6':
	            	if(A||B)
	            		bVal=1;
	            	pushEval(&temp, bVal);
	            	break;
	            case '!':
	            	if(A!=B)
	            		bVal=1;
	            	pushEval(&temp, bVal);
	            	break;
	            	
	            default:valid=0; 
						printf("\nInvalid input...");
	        }
		}
	}
		if(valid)
	    	return temp.intContent[temp.top2];
	    	
	    return 0;
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
		else if(isdigit(str[i]))
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
	
	char postfix[MAX];
	int i = 0;
	
	printf("Input:\n");
	getLongString(input.strContent);
	parser(input.strContent,postfix, strlen(input.strContent));
	printf("Postfix: ");
	for(i=0; i<strlen(postfix); i++)
		printf("%c", postfix[i]);

	
	
	printf("\nCalculation: %d \n", postfixEvaluation(postfix));
	
	return 0;
}
