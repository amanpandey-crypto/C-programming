//Program to find transpose of matrix
#include<stdio.h>
int main()
{
    int row,col,i,j,arr1[20][20];
    printf("Enter the no.of rows and columns:\n");
    scanf("%d%d",&row,&col);
    printf("Enter the elements :\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        scanf("%d",&arr1[i][j]);
    }
    printf("The matrix before transpose is:\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
	printf("%d\t",arr1[i][j]);
        printf("\n");
    }
    printf("Transpose of matrix is \n");
    for (j = 0; j < col; ++j)
    {
        for (i = 0; i < row; ++i)
        {
            printf("%d\t", arr1[i][j]);
        }
        printf("\n");
    }
    return 0;
}
