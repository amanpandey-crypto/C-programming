//Program to find sum and difference of given two matrix
#include<stdio.h>
int main()
{
    int row,col,i,j,arr1[20][20],arr2[20][20],arr3[20][20];
    printf("Enter the rows and columns:\n");
    scanf("%d%d",&row,&col);
    printf("Enter the elements of first matrix:\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        scanf("%d",&arr1[i][j]);
    }
    printf("The first matrix is:\n"); 
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        printf("%d ",arr1[i][j]);
        printf("\n");
    }
    printf("Enter the elements of second matrix:\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        scanf("%d",&arr2[i][j]);
    }
    printf("The second matrix is:\n");
    
	for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        printf("%d ",arr2[i][j]);
        printf("\n");
    }
     
	for(i=0;i<row;i++)
    {   
        for(j=0;j<col;j++) 
        arr3[i][j]=arr1[i][j]+arr2[i][j];
    }
    
    printf("the sum of matrix is:\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        printf("%d ",arr3[i][j]);
        printf("\n");
    }
    int arr4[20][20];
    for(i=0;i<row;i++)
    {   
        for(j=0;j<col;j++) 
        arr4[i][j]=arr1[i][j]-arr2[i][j];
    }
        printf("the difference of matrix is:\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        printf("%d ",arr4[i][j]);
        printf("\n");
    }
    return 0;
}
