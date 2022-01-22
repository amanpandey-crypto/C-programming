
#include"msm19b040_listset.h"

int main()
{
    while(1)
    {
        int choice;
        struct node *list=NULL;
        printf("\n1.Insert\n2.Exit");
        printf("\nEnter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insert(list);
                break;
            case 2:
                exit(0);
            default:
                printf("Invalid choice, retry!!!");
        }  
    }
    return 0;
}