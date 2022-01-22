//Program to print the words ending with letter S in a given string
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
char str[100];

void main()
{
    int i, t, j, len;
    printf("Enter a string : ");
    gets(str);
    len = strlen(str);
    str[len] = ' ';
    for (t = 0, i = 0; i <= len; i++)
        {
            if (((str[i] == ' ') ||(str[i]==',')||(str[i]==':')||(str[i]==';')||(str[i]=='.')||(str[i]=='\0'))&& (str[i - 1] == 's'))
                {
                    for (j = t; j < i; j++)
                        printf("%c", str[j]);
                    t = i + 1;
                    printf(" ");
                }
            else
                {
                    if (str[i] == ' ')
                        {
                            t = i + 1;
                        }
                }
        }
}