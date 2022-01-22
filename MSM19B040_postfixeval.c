//program to do evaluation of postfix


#include<stdio.h>
#include<stdlib.h>
#include"evalstack.h"


//main function
int main(int argc, char **argv)
{
    struct Stack* st=(struct Stack*)malloc(sizeof(struct Stack));

    st->top=-1; 
    st->push=push2;
    st->pop=pop2;  
    st->display=display2;

    int i,num,cal;
    if(argc<2)
    {
        printf("Invalid Input"); 
        exit(0);
    }

    for(i=1;i<argc;i++)
    {
        if(argv[i][0]>='0'&&argv[i][0]<='9')
        {
            num=atoi(argv[i]);st->push(num,st);    //atoi converts string to number
        }
        else
        {
            int x=st->arr[st->top];
            st->pop(st);
            int y=st->arr[st->top];
            st->pop(st);
            if(argv[i][0]=='+')
                st->push(x+y,st);
            else if(argv[i][0]=='-')
                st->push(y-x,st);
            else if(argv[i][0]=='/')
                st->push(y/x,st);
            else if(argv[i][0]=='*')
                st->push(y*x,st);
            else if(argv[i][0]=='^')
                st->push(pow(y,x),st);
        }
    }
    printf("%d",st->arr[st->top]); 
    return 0;
}