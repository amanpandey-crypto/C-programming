//program to implement stack using singly linked list 

#include"linkedl.h"

int main()
{
    int choice, value, n;
    printf("\n--Stack Implementation using singly linked List--\n");
    while(1)
   {
        printf("1.Push\n2. Pop \n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
        case 1: 
            printf("Enter the value to be insert: ");
            scanf("%d", &value);
            InsertB(value);
            break;
        case 2: 
            DeleteB(); 
            break;
        case 3: 
            display();
            break;
        case 4: 
            exit(0);
        default: 
            printf("\nInvalid input,try again!!!\n");
        }
    } 
}