#include<stdio.h>
int main()
{
    int num,i,j;
    int listcount=0;
    scanf("%d",&num);
    for(i=2;i<=num;i++)
    {
        for(j=1;j<=i;j++)
        {
            if(i%j==0)
            {
              listcount++;
            }
        }
        if(listcount==2)
        {
            printf("%d ",i);
        }
    }
    return 0;
}