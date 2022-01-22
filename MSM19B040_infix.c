//Program to convert infix to postfix
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "stack.h"

#define SIZE 10


int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}

int priority(char symbol)
{
	if(symbol == '^')/* exponent operator, highest precedence*/
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')          /* lowest precedence */
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

int InfixToPostfix(char infix_exp[])
{ 
	char item;
    char ch;
    struct stack2 stk2;
    stk2->push2=push2;
    stk2->display2=display2;
    stk2->pop2=pop2;
    stk2->top=-1;
	printf("Post fix expression:");
    int i=0, k=-1;
	while(infix_exp[i]!='\0')        /* run loop till end of infix expression */
	{
		if(infix_exp[i] == '(')
		{
			push2(infix_exp[i],stk2);
			
		}
		else if(((infix_exp[i]>='a')&&(infix_exp[i]<='z'))||((infix_exp[i]>='A')&&(infix_exp[i]<='Z')))
		{
			infix_exp[++k]=infix_exp[i];
		}
		else if(infix_exp[i] == ')')          // if current symbol is ')' then 
		{
			                                  // pop and keep popping until
			while(stk2->arr[stk2->top] != '(')      // '(' encounterd 
			{
				pop2(stk2);
			}
			stk2->top--;
		}	
		else if(is_operator(infix_exp[i]) == 1)
		{
			
			while(is_operator(stk2->arr[stk2->top]) == 1 && priority(stk2->arr[stk2->top])>= priority(infix_exp[i]))
			{
				infix_exp[++k]= pop2(stk2);
			}
			push2(infix_exp[i],stk2);	
		}
		
	
		else
		{ //if current symbol is neither operand not '(' nor ')' and nor operator 
			printf("\nInvalid infix Expression.\n");
			getchar();
			exit(0);
		}
		i++; 
	}
	while (stk2.top == -1) 
        infix_exp[++k] = pop2(stk2); 
  
    infix_exp[++k] = '\0'; 
    printf( "%s", infix_exp ); 
}


int main()
{
    char infix[SIZE]; 
    printf("\nEnter Infix expression : ");
	scanf("%s",infix);
	InfixToPostfix(infix);          
	return 0;
    
}