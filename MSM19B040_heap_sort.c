//program to implement heap sort
#include <stdio.h>
#include<stdlib.h>

int size=0;

//swap function
void swap_int(int *n1, int *n2)
{
    int temp = *n2;
    *n2 = *n1;
    *n1 = temp;
}

//function to heapify the array
void Heapify(int array[], int size, int item)
{
    int max=item;
    int left=2*item+1;
    int right=2*item+2;
    if (left < size && array[left] > array[max])
    {
        max=left;
    }
    else if (right<size && array[right] > array[max])
    {
        max=right;
    }
    if (max!=item)
    {
        swap_int(&array[item], &array[max]);
        Heapify(array, size, max);
    }
}

//function for isertion of element
void Insert(int array[], int data)
{
    array[size] = data;
    size += 1;
    for (int i = (size/2) - 1; i >= 0; i--)
    {
        Heapify(array, size, i);
    }
}

//function to delete element
void Del(int array[], int data)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (data == array[i])
        {
            swap_int(&array[i], &array[size - 1]);
            size -= 1;
            for (int i = size / 2 - 1; i >= 0; i--)
            {
                Heapify(array, size, i);
            }
            return;
            
        }
    }
    printf("Element is not there.\n");
}

//function to do heap sort
void Hsort(int array[]) 
{
    for (int i=size-1; i>=0; i--) 
    {
        swap_int(&array[0], &array[i]);
        Heapify(array, i, 0);
    }
}


//function to display the heap
void showheap(int array[])
{
    printf("\nElements in the heap:");
    for (int i=0; i<size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

//main function
int main()
{
    int array[size+1];
    while(1)
    {
        int choice,value;
        printf("\n--Menu Operations--");
        printf("\n 1. Insert\n 2. Delete\n 3. Heap sort\n 4. display");
		printf("\n 5. Exit the program ");
		printf("\n Enter Your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
                printf("Enter element to insert:");
                scanf("%d",&value);
                Insert(array,value);
                showheap(array);
                break;
            case 2:
                printf("Enter element to delete:");
                scanf("%d",&value);
                Del(array,value);
                printf("%d deleted.",value);
                showheap(array);
                break;
            case 3:
                Hsort(array);
                showheap(array);
                break;
            case 4:
                showheap(array);
                break;
            case 5:
                printf("Completed");
                exit(0);
            default:
                printf("Invalid input, try again!!");
        }
    }
    return 0;
}