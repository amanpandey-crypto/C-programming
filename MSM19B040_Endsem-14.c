//Program End Sem- To find the maximum sum of a subsequence such that no 2 numbers in the subsequence are adjacent in the given circular array
#include <stdio.h>
#include<stdlib.h>

//using max function to find maximum of two numbers
int max(int num1, int num2)
{
   if(num1 > num2)
   {
      return num1;
   }
   return num2;
}

//finding sum of susequence terms
int SubSeqSum(int Carray[], int first, int last, int cap) 
{
   int array[cap],i;
   int Msum = 0;
   for (i=first; i<=last; i++) //from first element before last
   {
      array[i] = Carray[i];
      if (Msum < Carray[i])
      {
         Msum = Carray[i];
      }
   }
   for (i=(first+2); i<=last; i++) //starting from 2 index after first before last
   {
      for (int j = 0; j < i - 1; j++) 
      {
         if (array[i] < array[j] + Carray[i]) 
         {
            array[i] = array[j] + Carray[i];
            if (Msum < array[i])
            {
               Msum = array[i];
            }
         }
      }
   }
   printf("\nIn-between steps: %d", Msum);
   return Msum;
}

//finding max sum of subsequence
int maxSum(int Carray[], int cap)
{
   int sumArr1 = SubSeqSum(Carray, 0, (cap-2), cap); //sum of subsequence for first array from index 0 to n-2
   int sumArr2 = SubSeqSum(Carray, 1, (cap-1), cap); //sum of subsequence for second array from index 1 to n-1
   int sumMax = max(sumArr1, sumArr2); // finding maximum of two array subsequence
   return sumMax;
}
 
//main function
int main()
{
   int cap;
   printf("Enter the capacity of the circular array:");
   scanf("%d", &cap);
   int Carray[cap]; //declaring circular array
   printf("Enter %d elements:", cap);
   for(int i=0; i<cap; i++)
   {
      scanf("%d", &Carray[i]);
   }
   int sub=maxSum(Carray, cap);
   printf("\nMaximum sum of subsequence : %d", sub);
   return 0;
}