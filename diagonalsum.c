//Program to find the sum of the main and opposite diagonal elements of a matrix
#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,a[100][100],row,col,msum=0,oppsum=0;
    printf("Enter the rows and columns of the matrix:\n");
    scanf("%d%d",&row,&col);
    if (row==col)
    {
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
                msum=msum+a[i][i];
                oppsum+=a[i][row-i-1];
            }
            printf("The sum of main diagonal is %d\n",msum);
            printf("The sum of opposite diagonal is %d\n",oppsum);
    }    
    else
    {
        printf("The given order matrix is not square matrix\n");
    }
    return 0;
}