//header file for stack operations
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

//structure for character stack operations
struct stack1
{
	int top;
	int arr[SIZE];
	void (*push1)(int,struct stack1*);
	void (*display1)(struct stack1*);
	void (*pop1)(struct stack1*);
};
void push1(int,struct stack1*);
void display1(struct stack1*);
void pop1(struct stack1*);


//structure for character stack operations
struct stack2
{
	int top;
	char arr[SIZE];
	void (*push2)(char,struct stack2*);
	void (*display2)(struct stack2*);
	void (*pop2)(struct stack2*);
};
void push2(char,struct stack2*);
void display2(struct stack2*);
void pop2(struct stack2*);

   
//Function to push an integer into the stack
void push1(int num,struct stack1 *sta)
{
    if(sta->top == SIZE-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        sta->top=sta->top + 1;
        sta->arr[sta->top]=num;
    }
}

//function to pop an integer from the Stack
void pop1(struct stack1 *sta)
{
    if(sta->top == -1)
    {
        printf("The stack is empty.\n");
    }
    else
    {
        sta->top=sta->top - 1;
    }
}

//Function to display the contends in the Stack
void display1(struct stack1 *sta)
{
    if(sta->top==-1)
    {
        printf("The stack is empty\n");
    }
    else
    {
        for(int i=sta->top; i>-1; i--)
        {
            printf("%d\n",sta->arr[i]);
        }
	    printf("\n");   
    }
}


//Function to push a character into the stack
void push2(char ch,struct stack2 *st)
{
          
    if(st->top == SIZE-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        st->top=st->top + 1;
        st->arr[st->top]=ch;
    }
}
//function to pop a characer from the Stack
void pop2(struct stack2 *st)
{
    if(st->top == -1)
    {
        printf("The stack is Empty\n");
    }
    else
    {
        st->top=st->top - 1;
    }
}

//Function to display the contends in the Stack
void display2(struct stack2 *st)
{
    if(st->top==-1)
    {
        printf("The stack is empty\n");
    }
    else
    {
        for(int i=st->top; i>-1; i--)
        {
            printf("%c\n",st->arr[i]);
        }
	printf("\n");   
    }
}