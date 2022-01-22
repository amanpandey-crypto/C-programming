#include <stdio.h> 
#include <stdlib.h>
void main() 
{ 
    FILE *fptr1, *fptr2;  
    int c;
    fptr1 = fopen("b.txt", "rb"); 
    if (fptr1 == NULL) 
    { 
        printf("Cannot open file %s \n"); 
        exit(0); 
    }
    fptr2 = fopen("c.txt", "wb");
    while (c != EOF) 
    { 
        c=getw(fptr1);
        putw(c,fptr2);
    }  
    fclose(fptr1); 
    fclose(fptr2);
    printf("\nContents copied"); 
}
