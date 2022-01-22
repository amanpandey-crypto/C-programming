//Menu-Driven Program to search element using two different method

#include<stdio.h>
#include<stdlib.h>
#include"sort.h"    //header file


//Searching using binary search method
int BinSearch(int arr[], int n, int k)
{
    int left=0, right=n-1;
	int mid;
	while(left<=right)
    {
		mid=(left+right)/2;
		if(k==arr[mid])
        {
			return mid;
		}
		else if(k<arr[mid])
        {
			right=mid-1;
		}
		else
        {
			left=mid+1;
		}
	}
	return -1;
}


//Seraching using linear search method
int LinSearch(int arr[], int n, int k)
{
    for (int j = 0 ; j <n ; j++ )
    {
        if (arr[j] == k )    //comparing key value with elements
        {
            return j;
        }
    }
    return -1;
}


//Main Program
int main()
{
    int n, arr[100], i, k, choice, find, ans, arr1[100];
    printf("Enter no. of elements :");
    scanf("%d", &n);
    printf("\nEnter the elements of array :");
    
    //checking the validity of n
    if(n<=5)
    {
        printf("\nNeed more elements.");
        exit(0);
    }
    for( i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
        arr1[i]=arr[i];   //assigning value to another array
    }
    printf("\nEnter the element to search :");
    scanf("%d", &k);
    int *sorted_arr=SelectionSort(arr,n);  //sorting using header file (any one method)
    while(1)
    {
        printf("\nPress 1: Binary search \nPress 2: Linear search \nPress 3: Exit the program");
        printf("\nEnter your choice :");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                find=BinSearch(sorted_arr, n, k);
                if(find==-1)                         //displaying the position
                {
		            printf("Given Key value is not present.\n");
	            }
	            else
                {
		            printf("Key value %d is present at %d location.\n", k, find+1);
	            }
                   break;
            case 2: 
                ans=LinSearch(arr1, n, k);
                if(ans==-1)                        //displaying the position
                {
		            printf("Given Key value is not present.\n");
	            }
	            else
                {
		            printf("Key value %d is present at %d location.\n", k, ans+1);
	            }
                break;
            case 3:
                exit(0);
            default: 
                printf("Please enter a valid choice!!\n");
                exit(0);
        }
    }
    return 0;
}