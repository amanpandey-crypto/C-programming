#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
}*newNode,*temp;

struct node *createnode()
{
    int data;
    scanf("%d",&data);
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void display(struct node* start)
{
    temp=start;
    if(start==NULL)
    {
        printf("\nThe List is empty.");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
    }
}
struct node *create(struct node* head, int val)
{
    int i;
    printf("\nEnter elements:");
    for(i=0; i<val; i++)
    {
        newNode = createnode();
        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp = head;
            while(temp -> next != NULL)
            {
                temp = temp -> next;
            }
            temp -> next = newNode;
            newNode->prev =temp;
        }
    }
    return head;
}

int search(struct node* head,int node_data)
{
    temp=head;
    if(head==NULL)
    {
        return 0;
    }
    else
    {
        while(temp!=NULL)
        {
            if(temp->data!=node_data)
            {
                temp=temp->next;
            }
            else
            {
                return 1;
            }
        }
    }
    return 0;
}
struct node *sort(struct node *start)
{
    struct node *ptr;
    for(temp = start; temp!=NULL; temp=temp->next)
    {
        for(ptr=temp->next; ptr!=NULL; ptr=ptr->next)
        {
            if(temp->data>ptr->data)
            {
                int k = temp->data;
                temp->data = ptr->data;
                ptr->data = k;
            }
        }
    }
    return start;
}

void insert(struct node *head)
{
    struct node *list;
    list= (struct node *)malloc(sizeof(struct node));
    list=head;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&newNode->data);
    newNode->next = NULL;
    newNode->prev = NULL;
    if(head==NULL)
    {
        head=newNode;
        printf("%d Inserted.\n",newNode->data);
    }
    else
    {
        if(search(head,newNode->data)!=1)
        {
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->prev=temp;
            printf("%d Inserted.\n",newNode->data);
        }
    }
    display(list);
}
