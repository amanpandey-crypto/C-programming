#include<stdio.h>
int main()
{
   int num,c,i,space;
   printf("Enter the number of rows:\n");
   scanf("%d",&num);
   for(i=1;i<=num;i++)
   {
      for(space=1;space<=num-i;space++)
         printf(" "); 
      for(c=1;c<=(2*i-1);c++)
         printf("*");
         printf("\n");
   }
   for(i=num-1;i>=1;i--)
   { 
      for(space=1;space<=num-i;space++)
         printf(" ");
      for(c=1;c<=(2*i-1);c++)
         printf("*");
         printf("\n");
   }
   return 0;
}
      
