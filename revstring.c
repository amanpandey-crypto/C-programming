//Program to print the string in reverse order
#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int i,j,listcount=0;
    printf("Enter the string:\n");
    scanf("%s",str);
    for(i=0;str[i]!='\0';i++)
    {
        listcount++;
    }
    for(j=listcount-1; j>=0; j--)
    {
        printf("%c", str[j]);
    }   
    return 0;
}