#include<stdio.h>
int main()
{
	 int a,b=a%2;
	 printf("Enter a value:\n");
	 scanf("%d",&a);
	 if(a%2==0)
	 b=0;
	 else 
	 b=1;
	 switch(b)
	 { 
	   case 1:printf("%d is an odd number\n",a);
		      break;
	   case 0:printf("%d is an even number\n",a);
		      break;
	 }         
	 return 0;  
}	   
