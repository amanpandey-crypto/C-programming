//Program to implement the averaging and scaling functions in different levels (Haar wavelet transform)

#include<stdio.h>
#include<stdlib.h>

//function to find averaging and scaling of elements in the array
void avgANDscale(int arr[],int n,int level,int num)
{
    printf("\nLEVEL %d\n",num);
    printf("Given array :");
    for(int i=0; i<n; i++)  //printing the given array
    {
        printf("%d ",arr[i]);
    }
    int m=(n+1)/2;
    int arr1[m];
    for(int i=0;i<m-1;i++)   //calculating the averaging of array in new array
    {
        arr1[i]=(arr[2*i]+arr[2*i+1]+1)/2;
    }
    if(!n%2) //checking for size of array is even or not
    {
        arr1[m-1]=(arr[2*(m-1)]+arr[2*(m-1)+1]+1)/2;
    }
    else 
    {
        arr1[m-1]=(arr[2*(m-1)]+1)/2;
    }
    printf("\nAveraging array is: ");  //printing the averaging of array
    for(int i=0; i<m ;i++) 
    {
        printf("%d ",arr1[i]);
    }
    int scal[m];
    for(int i=0;i<m;i++)    //calculating scaling of the previous array
    {
        scal[i]=abs(arr1[i]-arr[2*i]);
    }
    printf("\nScaling array is: ");
    for(int i=0; i<m ;i++)    //printing scaling array
    {
        printf("%d ",scal[i]);
    }
    if(level==2)
    {
        avgANDscale(arr1,m,0,2); //recalling it again for level=2
    }
}

//main program
int main()
{
    int sz,level;
    printf("\nEnter size of array :");
    scanf(" %d",&sz);
    printf("\nEnter level for the array :");
    scanf(" %d",&level);
    int arr[sz];
    printf("\nEnter the array :");
    for(int i=0; i<sz; i++) 
    {
        scanf(" %d",arr+i);
    }
    avgANDscale(arr,sz,level,1);  //calling for level 1
    return 0;
}