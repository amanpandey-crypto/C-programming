//Program to check whether a given matrix is identity matrix or not
#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,row,col,arr[100][100],temp=1;
    printf("Enter the rows and columns of the matrix:\n");
    scanf("%d%d",&row,&col);
    if (row==col)
    {
            printf("Enter the elements of the matrix:\n");
            for(i=0;i<row;i++)
            {
                for(j=0;j<col;j++)
                scanf("%d",&arr[i][j]);
            }
            printf("The given matrix is:\n");
            for(i=0;i<row;i++)
            {
                for(j=0;j<col;j++)
                printf("%d\t",arr[i][j]);
                printf("\n");
            }
            for(i=0;i<row;i++)
            {
                for(j=0;j<col;j++)
                {
                    if(i==j && arr[i][j]!=1 )
                    {
                        temp=0;
                        break;
                    }
                    else if(i!=j && arr[i][j]!=0)
                    {
                        temp=0;
                        break;
                    }
                }
            }
            if(temp==1)
            {
                printf("The matrix is an identity matrix.\n");
            }
            else
            {
                printf("The matrix is not an identity matrix.\n");
            } 
    }
    else
    {
        printf("Thae matrix is not a square matrix.\n");
    }
    return 0;
}