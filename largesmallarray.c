//Program to find largest and smallest element in array
#include<stdio.h>
int main()
{
    int size,arr[100],i,lar,sml;
    printf("Enter the size of the array:\n");
    scanf("%d",&size);
    printf("Enter the elements of an array\n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    lar=arr[0];
    sml=arr[0];
    for(i=1;i<size;i++)
    {
        if(lar<arr[i])
        lar=arr[i];
        else if(sml>arr[i])
        sml=arr[i];
    }
    printf("The largest and smallest element in the array is %d and %d\n",lar,sml);
    return 0;   
}
