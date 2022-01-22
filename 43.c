#include<stdio.h>
#include<stdlib.h>
int main(int argc,char*argv[])
{
    int i;
    if(argc>=2)
    {
        printf("\nThe argument given are :");
        for(i=1;i<argc;i++)
        {
            printf("\n%s\t",argv[i]);
        }
    }
    else
    {
        printf("\n No arguments are there.");
    }
    return 0;
}