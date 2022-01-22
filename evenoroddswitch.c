#include<stdio.h>
int main()
{
	int a;
	printf("enter a value:\n");
	scanf("%d",&a);
	switch(a%2)
	{
		case 0:
			printf("%d is an Even Number\n",a);
			break;
	    case 1:
	        printf("%d is odd number\n",a);
	        break;
	}
	return 0;
}
