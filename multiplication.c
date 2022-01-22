#include<stdio.h>

int multiplication(int);

int main()
{
	int num;
	printf("Enter a number for which you want a multiplication table:\t");
	scanf("%d", &num);
	multiplication(num);
	return 0;

}

	int multiplication(int number)
{
	int i;
	if(number<0)
	{
		printf("Error!");
	}
	else
	{
		for(i=1; i<=10; ++i)
		{
		printf("%d * %d = %d \n", number,i,number*i);
		}
	}
	return 0;
}
