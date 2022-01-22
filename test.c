#include <stdio.h> 
#include <stdlib.h>
void main() 
{
    int n; 
    FILE *fptr1;
    fptr1 = fopen("a.txt", "wb");
    if (fptr1 == NULL) 
    { 
        printf("Cannot open file %s \n"); 
        exit(0); 
    }
    printf("\nEnter some data : ");
    scanf("%d",&n);
    putw(n,fptr1);
    fclose(fptr1);
}