//Program to find the people(s) with integer 'k' and display their position(s)in the line
#include<stdio.h>
 
int displaypos(int arr[], int t)
{
   int j;
   for (j = 0 ; j <10 ; j++ )
   {
      if (arr[j] == t )
         return j;
   }
   return -1;
}
 
 // main program
int main()
{
   int arr[100], k, i, position;
   printf("Enter 10 integers :");
 
   for (i = 0 ; i <10 ; i++ )
      scanf("%d",&arr[i]);
 
   printf("\nEnter the integer 'k' to search :");
   scanf("%d",&k);
   position = displaypos(arr, k);
 
   if ( position == -1 )
      printf("%d is not present.\n", k);
   else
      printf("Person with integer %d is present at %d location.\n", k, position+1);
 
   return 0;
} 
 

 