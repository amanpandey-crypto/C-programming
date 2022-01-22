#include"linkedl.h"

int main()
{
   int choice, data, n;
   printf("\n--Queue Implementation using singly Linked List--\n");
   while(1)
   {
        printf("1. Enqueue\n2. Dequeue \n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
        case 1: 
            printf("Enter the value to be insert: ");
            scanf("%d", &data);
            InsertB(data);
            break;
        case 2: 
            DeleteE(); 
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