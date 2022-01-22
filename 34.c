#include<stdio.h>
int main()
{
    char str[100],*p;
    int listcount=0;
    printf("Enter the string :");
    gets(str);
    p=str;
    while(*p!='\0')
    {
         listcount++;
         p++;
    }
    printf("The length of the string is %d",listcount);
    return 0;
}