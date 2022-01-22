#include<stdio.h>
int main()
{
    int num,tempnum;
    printf("Enter a number:\n");
    scanf("%d",&num);
    num=tempnum;
    num=num<<2;
    printf("%d*4=%d",num,tempnum);
    return 0;
}
