#include<stdio.h>
float median(int n, int x[])
{
    int temp;
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(x[j]<x[i])
            {
                temp=x[i];
                x[i]=x[j];
                x[j]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("\n After sorting :%d",x[i]);
    }
    if(n%2==0)
    {
        return((x[n/2]+x[(n/2)-1])/2);
    }
    else
    {
        return(x[n/2]);
    }
    return 0;
}
void main()
{
    int x[100],n,i;
    printf("\nEnter the size of array :");
    scanf("%d",&n);
    printf("\n Enter the elements :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
    printf("\nThe median is %.2f",median(n,x));
}