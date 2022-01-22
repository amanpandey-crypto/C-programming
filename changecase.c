//Program to change case of all characters in a string
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int i;
    char a[20],ch;
    printf("Enter a string:\n");
    gets(a);
    while(a[i]!='\0')
    {
        ch=a[i];
	    if(ch>='A'&& ch<='Z')
	    {
		    a[i]=a[i]+32;
	    }
	    else if(ch>='a' && ch<='z')
	    {
		    a[i]=a[i]-32;
	    }
        i++;
    }
    puts(a);
    return 0;
}
