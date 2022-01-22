#include<stdio.h>
int main()
{
int a,b;
char ch;
printf("enter a character\n");
scanf("%c",&ch);
printf("enter two numbers:\n");
scanf("%d%d",&a,&b);
if(ch=='+')
{
printf("the addition is %d\n",a+b);
}
else if(ch=='-')
{
printf("the sub is %d\n",a-b);
}
else if(ch=='*')
{
printf("the mult is %d\n",a*b);
}
else if(ch=='/')
{
printf("the quot is %d\n",a/b);
}
else if(ch=='%')
{
printf("the remaind is %d\n",a%b);
}
else 
{
printf("invalid operators\n");
}
return 0;
}
