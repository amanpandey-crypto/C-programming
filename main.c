//program for evaluation of postfix expression
//In program for operator "*" use lowercase "x"
//In program for operator "^" use lowercase "e"

#include<stdio.h> 
#include<stdlib.h>

#include "stack.h"
int operator_ex(int , struct stack*); //function declaration

//function for calculating x^y
int _pow(int x, int y)
    {
	    int out = 1;
	    for (int i = 0; i < y; ++i)
	    {
		    out*=x;
	    }
	return out;
    }
   

  
int main(int argc, char const *argv[])
{
    
    int i,j;
    struct stack stack1;
    stack1.top = -1;
    stack1.display = display;
    stack1.push = push;
    stack1.pop = pop;
	
	for(j=1; j<argc; j++)
    {
        int convert=atoi(argv[j]);
        if(convert==0 || argv[j]=="x" || argv[j]=="e" )
        {
			operator_ex(argv[j][0], &stack1);
        }
        else
        {
            stack1.push(convert, &stack1);
        }
        
    }
    int output = stack1.pop(&stack1);
    printf("Answer: %d\n", output);
    return 0;
}

int operator_ex(int symbol, struct stack *stack_ptr)
{
	int x, y;
	switch (symbol)
	{
		case 43: // ascii value of +
			y = stack_ptr->pop(stack_ptr);
			x = stack_ptr->pop(stack_ptr);
			stack_ptr->push(x+y, stack_ptr);
			break;
		case 45: // ascii value of -
			
			y = stack_ptr->pop(stack_ptr);
			x = stack_ptr->pop(stack_ptr);
			stack_ptr->push(x-y, stack_ptr);
			break;
		case 120: // ascii value of x(*)
			y = stack_ptr->pop(stack_ptr);
			x = stack_ptr->pop(stack_ptr);
			stack_ptr->push(x*y, stack_ptr);
			break;
		case 47: // ascii value of /
			
			y = stack_ptr->pop(stack_ptr);
			x = stack_ptr->pop(stack_ptr);
			stack_ptr->push(x/y, stack_ptr);
			break;
		case 101: // ascii value of e(^)
			
			y = stack_ptr->pop(stack_ptr);
			x = stack_ptr->pop(stack_ptr);
			printf("%d %d\n", x, y);
			stack_ptr->push(_pow(x,y), stack_ptr);

			break;
		default:
		    printf("finish\n");
			break;
	}
	return 0;
}

