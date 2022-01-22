// Programs for swapping two numbers by using bitwise XOR operators
#include<stdio.h>
int main()
{
  int num1,num2;
  printf("Enter two numbers:\n");
  scanf("%d%d",&num1,&num2);
  printf("The numbers before swapping is %d and %d \n",num1,num2);
  num1=num1^num2;
  num2=num1^num2;
  num1=num1^num2;
  printf("The numbers after swapping is %d and %d \n",num1,num2);
  printf("Completed");
  return 0;
}
