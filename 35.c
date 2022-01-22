#include<stdio.h>
#include<string.h>
int main()
{
    char str[100],*p;
    int sum=0 ,i;
    printf("Enter the string:");
    gets(str);
    p=str;
    while(*p!='\0')
    {
        sum=sum+ *p;
        p++;
    }
    printf("The sum of ASCII values is %d",sum);
}