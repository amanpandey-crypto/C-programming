#include<stdio.h>
int main() 
{
   int arr[10];
   int i,n,sum = 0;
   int *ptr;
   printf("Enter the size of the array:");
   scanf("%d",&n);
   printf("\nEnter the elements : ");
   for (i = 0; i < n; i++)
   {
        scanf("%d", &arr[i]);
   }   
   ptr = arr;
   for (i = 0; i < n; i++) 
   {
      sum = sum + *ptr;
      ptr++;
   }
   printf("The sum of array elements : %d", sum);
   return 0;
}