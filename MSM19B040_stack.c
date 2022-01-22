//Program to implement stack doing main operations(push and pop)
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10


void stack_int();
void stack_char();

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



//main function
int main()
{
    int option;
    printf("CHOOSE TYPE OF STACK\n");
    printf("      1.      INTEGER STACK    \n");
    printf("      2.      CHARACTER STACK   \n");
    scanf("%d",&option);
    switch(option)
    {
        case 1:
            printf("Integer stack :\n");
            stack_int();
            break;
        case 2:
            printf("Character stack :\n");
            stack_char();
            break;
        default:
            printf("Wrong input.\n");
    }
}

// functions for choosing operations of integer stack    
void stack_int()    
{
    int num,choice;
    struct stack1 stk1;
    stk1.push1=push1;
    stk1.display1=display1;
    stk1.pop1=pop1;
    stk1.top=-1;
    printf ("STACK OPERATION\n");
    while (1)
    {
        printf ("      1.    PUSH               \n");
        printf ("      2.    POP               \n");
        printf ("      3.    DISPLAY               \n");
        printf ("      4.    EXIT           \n");
 
        printf ("Enter your choice:");
        scanf    ("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter a number to be pushed:");
            scanf("%d", &num);
            stk1.push1(num,&stk1);
            break;
        case 2:
            stk1.pop1(&stk1);
            break;
        case 3:
            stk1.display1(&stk1);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid Input, try again!!\n");
        }
    }
}

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
        printf("%d is popped out\n", sta->arr[sta->top]);
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
        printf("After doing stack operations, stack is :\n");
        for(int i=sta->top; i>-1; i--)
        {
            printf("%d\n",sta->arr[i]);
        }
	    printf("\n");   
    }
}

// functions for choosing operations of character stack
void stack_char()
{
    int choice;
    char ch;
    struct stack2 stk2;
    stk2.push2=push2;
    stk2.display2=display2;
    stk2.pop2=pop2;
    stk2.top=-1;
    printf ("STACK OPERATION\n");
    while (1)
    {
        printf ("      1.    PUSH               \n");
        printf ("      2.    POP               \n");
        printf ("      3.    DISPLAY               \n");
        printf ("      4.    EXIT           \n");
 
        printf ("Enter your choice:");
        scanf    ("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter a character to be pushed:\n");
                scanf(" %c", &ch);
                stk2.push2(ch,&stk2);
                break;
            case 2:
                stk2.pop2(&stk2);
                break;
            case 3:
                stk2.display2(&stk2);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Input, try again!!\n");
        }
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
        printf("%c is popped out\n", st->arr[st->top]);
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
        printf("Stack after doing operations :\n");
        for(int i=st->top; i>-1; i--)
        {
            printf("%c\n",st->arr[i]);
        }
	printf("\n");   
    }
}