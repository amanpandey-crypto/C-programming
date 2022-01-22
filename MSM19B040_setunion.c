//header file to get the union of two doubly linked list
#include "msm19b040_listset.h"

int main()
{
    struct node *l1=NULL,*l2=NULL,*l3=NULL;
    int s1,s2;

    printf("\nEnter the size(list1): ");
    scanf("%d",&s1);
    l1 = create(l1,s1);
    printf("\nEnter the size of list 2: ");
    scanf("%d",&s2);
    l2 = create(l2,s2);
    printf("\nAfter taking Union of two list:");
    struct node *curr;
    for(curr=l1; curr!=NULL; curr=curr->next)
    {
        if(search(l3,curr->data)!=1)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            newNode->data=curr->data;
            newNode->prev=NULL;
            newNode->next=NULL;
            if(l3==NULL)
            {
                l3=newNode;
            }
            else
            {
                temp=l3;
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=newNode;
                newNode->prev=temp;
            }
        }
    }
    for(curr=l2; curr!=NULL; curr=curr->next)
    {
        if(search(l3,curr->data)!=1)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            newNode->data=curr->data;
            newNode->prev=NULL;
            newNode->next=NULL;
            if(l3==NULL)
            {
                l3=newNode;
            }
            else
            {
                temp=l3;
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=newNode;
                newNode->prev=temp;
            }
        }
    }
    display(l3);
}