//Menu-Driven program for different type of sorting method

#include<stdio.h>
#include<stdlib.h>

//Function for displaying array after each pass
int display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf(" %d ",arr[i]);
    }
    printf("\n");
}

//swapping the elements of array
void SwapElement(int *a, int *b)
{     
	int swap ;
	swap= *a ;
	*a=*b ;
	*b=swap ;
}


//Function for bubble sorting
int BubbleSort(int arr[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                SwapElement(&arr[j],&arr[j+1]);
            }
        }
        display(arr,n);
    }   
}

//Function for insertion sorting
int InsertionSort(int arr[], int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        j=i;
        while(j>0)
        {
            if(arr[j]<arr[j-1])
            {
               SwapElement(&arr[j],&arr[j-1]);
            }
            j--;
        }
        display(arr,n);
    }
}

//Function for selection sorting
int SelectionSort(int arr[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        int min=i ;
		for(j=i+1;j<n;j++)
		{	
            if(arr[j]<arr[min])
			{ 	
				min=j ; 
			}
        }
        SwapElement(&arr[i],&arr[min]);
        display(arr,n);
    }
}


//Main function
int main()
{
    int n, arr[100], arr1[100], arr2[100], choice;
    printf("Enter no. of elements in array :");
    scanf("%d",&n);
    if(n<=5) //checking the validity of n
    {
        printf("Invalid input.");
        exit(0);
    }
    printf("\nEnter the elements :");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
        arr1[i]=arr[i];
        arr2[i]=arr[i];
    }
    while(1)
    {
 
        printf("\n1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\n4. Exit the Program.\n");
        printf("\nEnter your Choice : ");
        scanf("%d",&choice);
 
        switch(choice)
        {
            case 1:
                printf("After Using Bubble sort :\n"); 
                BubbleSort(arr,n);
                break;
            case 2:
                printf("After Using Insertion sort :\n");
                InsertionSort(arr1,n);
                break;
            case 3:
                printf("After Using Selection sort :\n");
                SelectionSort(arr2,n);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
                exit(0);
        }
    }
    return 0;
}