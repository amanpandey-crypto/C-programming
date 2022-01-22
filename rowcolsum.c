// Program to find the sum of rows and columns of the matrix
#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,a[100][100],row,col,rsum,csum;
    printf("Enter the rows and columns of the matrix:\n");
    scanf("%d%d",&row,&col);
    printf("Enter the elements of the matrix:\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        scanf("%d",&a[i][j]);
    }
    printf("The given matrix is:\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        printf("%d\t",a[i][j]);
        printf("\n");
    }
    for(i=0;i<row;i++)
    {
        rsum=0;
        for(j=0;j<col;j++)
        {
            rsum+=a[i][j];
        }
        printf("The sum of element of row %d = %d\n",i+1,rsum);
    }
    for(i=0;i<row;i++)
    {
        csum=0;
        for(j=0;j<col;j++)
        {
            csum+=a[j][i];
        }
        printf("The sum of element of column %d = %d\n",i+1,csum);
    }
    return 0;
}

            