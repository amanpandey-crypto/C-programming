//program to implement the front and back functionality of a browser

#include<stdio.h>
#include<stdlib.h>
#include"msm19b040_dll.h"

//menu driven main program
int main()
{
    printf("----Choose Operations----\n");
    printf("1. Insert a page\n");
    printf("2. Next page\n");
    printf("3. Previous page\n");
    printf("4. Display Current Page\n");
    printf("5. Display all page\n");
    printf("6. Exit the program\n");
    int choice;
    while (1)
    {
        printf ("\nEnter choice: ");
        scanf(" %d", &choice);
        switch (choice)
        {
            case 1:
                ins_page();
                break;
            case 2: 
                next_page(); 
                break;
            case 3: 
                prev_page();
                break;
            case 4: 
                display_curr(); 
                break;
            case 5: 
                display_all();  
                break;
            case 6:
                printf("Exiting the program\n");
                exit(0);
            default: 
                printf("Invalid choice, try again!!\n");
        }
    }
    return 0;
}