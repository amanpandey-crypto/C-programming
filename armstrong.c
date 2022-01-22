//program to find whether a given number is armstrong or not
#include<stdio.h>
#include<math.h>
int main()
{
  int n,originalnumber,rem,result=0,noofdigits;
  printf("Enter a number:\n");
  scanf("%d",&n);
  int i=n;
  while(i!=0)
  {
    i=i/10;
    noofdigits++;
  }
  printf("The number of digits is %d\n",noofdigits);
  originalnumber = n;
  while(originalnumber!=0)
  {
     rem=originalnumber%10;
     result=result+pow(rem,noofdigits);
     originalnumber=originalnumber/10;
  }
  if(result==n)
    {
      printf("The given number %d is an armstrong number\n",n);
    } 
  else  
    {
      printf("The given number %d is not an armstrong number\n",n);
    }
    return 0;
 }  
