//Alternate logic to find the people(s) with integer 'k' and display their position(s)in the line

#include<stdio.h>
 
int altlogic(int *pointer,int n)
{
   int j;
   for ( j = 0 ; j < 10 ; j++ )
   {
      if ( *(pointer+j) == n )
         return j;
   }
   return -1;
}
 
int main()
{
   int arr[100], k, i, pos;
   printf("Enter 10 integers :");
 
   for (i = 0 ; i <10 ; i++ )
      scanf("%d",&arr[i]);
 
   printf("\nEnter the integer 'k' to search :");
   scanf("%d",&k);
   pos = altlogic(arr, k);
 
   if ( pos == -1 )
      printf("%d is not present.\n", k);
   else
      printf("Person with integer %d is present at %d location.\n", k, pos+1);
 
   return 0;
} 
 
