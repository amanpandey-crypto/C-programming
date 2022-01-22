//Header file includes different sorting method

#include<stdio.h>

int *bubblesort(int *array,int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(*(array+j)>*(array+(j+1)))
            {
                temp=*(array+j);             //swapping elements of array
                *(array+j)=*(array+(j+1));
                *(array+(j+1))=temp;
            }
        }
    }
    return array;
}
int *InsertionSort(int *array, int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        j=i;
        while(j>0)
        {
            if(*(array+(j))<*(array+(j-1)))
            {
                temp=*(array+j);                   //swapping elements of array
                *(array+j)=*(array+(j-1));
                *(array+(j-1))=temp;
            }
            j--;
        }
    }
    return array;
}

int *SelectionSort(int *array,int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        int min=i ;           //assigning min value
		for(j=i+1;j<n;j++)
		{	
            if(*(array+(j))<*(array+(min)))
			{ 	
				min=j ; 
			}
        }
        temp=*(array+i);                    //swapping elements of array
        *(array+i)=*(array+(min));
        *(array+(min))=temp;
    }
    return array;
}