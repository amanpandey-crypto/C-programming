#include<stdio.h>
int main()
{ 
	int a;
	printf("enter the number of days:");
	scanf("%d",&a);
	if (a<365)
	{
		int b=a/7,c=a%7;
		printf("the number of weeks and days is %d,%d\n",b,c);
		scanf("%d%d",&b,&c);
	}
	else
	{
		int p=a%365,d=a/365,e=p/7,f=p%7;
		printf("the number of years,weeks,days is %d,%d,%d\n",d,e,f);
	}	
    printf("completed");
    return 0;
}
