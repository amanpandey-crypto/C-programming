//header file to evaluate postfix

#include<stdlib.h>
#include<string.h>
#include<math.h>


#define size 10


//Basic structure of a stack
struct Stack
{
    int top;
    int arr[size];
    void(*pop)(struct Stack*);
    void(*push)(int i,struct Stack*);
    void(*display)(struct Stack*);
};


//function to push element into stack
void push2(int i,struct Stack* st)
{
    if(st->top>=size)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        st->top++; st->arr[st->top]=i;
    }
}


//function to pop element 
void pop2(struct Stack* st)
{
    if(st->top<0) printf("The stack is empty\n");
    else st->top--;
}



//function to display the stack
void display2(struct Stack* st)
{
    if(st->top<0)
    {
        printf("Stack empty\n");
    }
    else 
    {
        while(st->top!=-1)
        { 
            printf("%d ",st->arr[st->top]); st->top--;
        }
        printf("\n");
    }
}