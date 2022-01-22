//Program to find the nth number of fibonacci series
#include<stdio.h>
int fibo(int);
int main()
{
    int n, a;
    printf("Enter the term to find:\n");
    scanf("%d",&n);
    a=fibo(n);
    printf("The value for %d fibo term is %d",n,a);
    return 0;
}
int fibo(int n)
{
    if(n==0||n==1)
    {
        return n;
    }
    else
    {
        return fibo(n-1)+fibo(n-2);
    }
}