#include<stdio.h>
int main()
{
   long num,dnum,rem,base=1,bin=0,no_of_1s=0;
   printf("Enter a decimal number\n");
   scanf("%ld",&num);
   dnum=num;
   while(num>0)
   {
      rem=num%2;
      if(rem==1)
      { 
         no_of_1s++;
      }
      bin=bin+rem*base;
      num=num/2;
      base=base*10;
   }
   printf("Input number is %ld\n",dnum);
   printf("\nThe binary equivalent is %ld",bin);
   printf("\nNo. of 1's in the binary number is %ld",no_of_1s);
   return 0;
}
