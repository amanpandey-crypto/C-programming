#include<stdio.h>
int fact(long int);
int main()
{
long int n,r,p,temp;
long int num,den;
printf("\nEnter the number of seats available :");
scanf("%ld",&r);
printf("\nEnter the number of persons : ");
scanf("%ld",&n);
if(n < r)
{
temp=n;
n=r;
r=temp;
}
num=fact(n);
den=fact(n-r);
p=num/den;
printf("\nNumber of ways people can be seated : ");
printf("%ld\n",p);
return 0;
}
int fact(long int x)
{
long int f=1,i;
for(i=1;i<=x;i++)
{
f=f*i;
}
return f;
}
