//Program by using bitwise operators
#include<stdio.h>
int main()
{
	int num1,num2,num3,num4;
	printf("Enter four numbers:\n");
	scanf("%d%d%d%d",&num1,&num2,&num3,&num4);
	int num5=num1&num2|num3&num4;
	int num6=num5*4;
	printf("The result if performing 4 * (%d & %d | %d & %d) is %d\n",num1,num2,num3,num4,num6);
	return 0;
}
