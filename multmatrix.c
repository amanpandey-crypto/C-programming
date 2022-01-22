#include<stdio.h>
int main()
{
    int i,j,p,q,m,n,k;
    int arr1[20][20],arr2[20][20],arr3[20][20];
    printf("Enter the rows and columns:\n");
    scanf("%d%d",&p,&q);
    printf("Enter the elements of first matrix:\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        scanf("%d",&arr1[i][j]);
    }
    printf("The first matrix is:\n"); 
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        printf("%d ",arr1[i][j]);
        printf("\n");
    }
    printf("Enter no. of rows and columns of second matrix:\n");
    scanf("%d%d",&m,&n);
    if(q!=m)
    {
       printf("The multiplication is not possible.\n");
    }
    else
    {
        printf("Enter elements of second matrix:\n");
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            scanf("%d",&arr2[i][j]);
        }
          printf("The second matrix is:\n"); 
	  for(i=0;i<m;i++)
	  {
             for(j=0;j<n;j++)
	     printf("%d ",arr2[i][j]);
	     printf("\n");
	  }
      for(i=0; i<p; ++i)
        for(j=0; j<n; ++j)
        {
            arr3[i][j] = 0;
        }
	  for(i=0;i<p;i++)
	  { 
              for(j=0;j<n;j++)
              {
                  for(k=0;k<m;k++)
                  {
                     arr3[i][j]+=(arr1[i][k]*arr2[k][j]);
                  } 
              }             
      }   
	  printf("The product of the matrices is:\n");
	  for(i=0;i<p;i++)
	  {
	     for(j=0;j<n;j++)
	     {
                printf("%d ",arr3[i][j]);  
             }
              printf("\n");
          }
    }
    return 0;
}
