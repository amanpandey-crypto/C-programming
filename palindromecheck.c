//program to check a given number is palindrome or not
#include<stdio.h>
int main() 
{
  int num, rem=0 ,t;
  printf("Enter a number\n");
  scanf("%d",&num);
  t=num;
  while(t!=0)
  {
     rem=rem*10;
     rem=rem+t%10;
     t=t/10;
  }
  if (num==rem)
  {
     printf("%d is palindrome number\n",num);
  }
  else
  {
     printf("%d is not palindrome number\n",num);
  }
  return 0;
}
