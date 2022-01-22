//Program to find the number of vowels and consonants in the string
#include<stdio.h>
#include<string.h>
int main()
{
    int i,vow=0,cons=0;
    char arr[100],ch;
    printf("Enter the string:\n");
    scanf("%s",arr);
    for(i=0;arr[i]!='\0';i++)
    {
        ch=arr[i];
        if(ch>=65 && ch<=90 || ch>=97 && ch<=122)
        {
            if(ch=='a'|| ch=='e'|| ch=='i'|| ch=='o'|| ch=='u'|| ch=='A'|| ch=='E'|| ch=='I'|| ch=='O'|| ch=='U')
            {
                vow++;
            }
            else
            {
                cons++;
            }
        }
        else
        {
            printf("NO alphabet is present.\n");
        }
    }
    printf("The vowels and consonants in the given string is %d and %d",vow,cons);
    return 0;
}