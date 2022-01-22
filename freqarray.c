#include <stdio.h>
int main()
{
    int arr[100], freq[100];
    int size, i, j, listcount;
    printf("Enter size of array:\n ");
    scanf("%d", &size);
    printf("Enter elements in array:\n ");
    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
        freq[i] = 0;
    }
    for(i=0; i<size; i++)
    {
        listcount = 1;
        for(j=i+1; j<size; j++)
        {
            if(arr[i]==arr[j])
            {
                listcount++;
                freq[j] = 1;
            }
        }
        if(freq[i] != 1)
        {
            freq[i] = listcount;
        }
    }
    printf("\nFrequency of all elements of array : \n");
    for(i=0; i<size; i++)
    {
        if(freq[i] != 1)
        {
            printf("%d occurs %d times\n", arr[i], freq[i]);
        }
    }

    return 0;
}