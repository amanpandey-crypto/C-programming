//Program to count the occurrence of each charecter ignoring the case of alphabets and display them
#include<stdio.h>
#include <string.h>
 
int main()
{
    char s[1000];  
    int  i,j,k,listcount=0,n;
 
    printf("Enter  the string : ");
    gets(s);
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]<='z'&&s[i]>='a')
		{
			s[i]=s[i]-32;
		}
	} 
    for(j=0;s[j]!='\0';j++);
	{
		n=j;
	} 
	printf(" frequency count character in string:\n");
    for(i=0;i<n;i++)  
    {
     	listcount=1;
    	if(s[i])
    	{
 		  for(j=i+1;j<n;j++)  
	      {
	        if(s[i]==s[j])
    	    {
                 listcount++;
                 s[j]='\0';
	     	}
	      }  
	      printf(" '%c' = %d \n",s[i],listcount);
       }   
 	}
    return 0;
}