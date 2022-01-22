//Program to read a string and find the sum of sum of all digits in the string
#include<stdio.h>
#include<string.h>
int main()
{
   char s[100];
    int i, listcount = 0, sum = 0;
 
    printf("Enter the string containing both digits and alphabet \n");
    gets(s);
    for (i = 0; s[i] != '\0'; i++)
    {
        if ((s[i] >= '0') && (s[i] <= '9'))
        {
            listcount++;
            sum = sum + (s[i] - '0');
        }
    }
    printf("NO. of Digits in the string = %d\n", listcount);
    printf("Sum of all digits = %d\n", sum);
    return 0;
}