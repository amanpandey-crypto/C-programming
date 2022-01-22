//header file of doubly linked list

#include<stdio.h>
#include<stdlib.h>

//structure to define a list node 
struct list_node
{
    struct list_node *prev;
    int data;
    struct list_node *next;
}*head=NULL,*temp,*curr=NULL,*newnode;


//structure to create a node
struct list_node *createnode()
{
    int data;
    printf("Enter a page number: \n");
    scanf("%d",&data);
    newnode=(struct list_node*)malloc(sizeof(struct list_node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}


//to display current webpage
void display_curr()
{
    if(curr==NULL)
    {
        printf("No webpages are there. Try Again!\n");
    }
    else
    {
        printf("The current webpage is %d\n",curr->data);
    }
}


//to display all pages 
void display_all()
{
    if(head==NULL)
    {
        printf("No webpages are there. Try Again!\n");
    }
    else
    {
        temp=head;
        printf("Availabe Webpages are: ");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}


//to insert a webpage
void ins_page()
{
    newnode=createnode();
    if(head==NULL)
    {
        head=newnode;
        curr=newnode;
    }
    else
    {
        temp=head;
        while(temp!=curr)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
        curr=newnode;
    }
    display_curr();
    printf("\n");
    display_all();
}

//function to go to next webpage
void next_page()
{
    if(head==NULL || curr->next==NULL)
    {
        printf("No webpages are there. Try Again!\n");
    }
    else
    {
        curr=curr->next;
        display_curr();
        printf("\n");
        display_all();
    }
}

//to go to previous webpage
void prev_page()
{
    if(head==NULL || curr->prev==NULL)
    {
        printf("No webpages are there. Try Again!\n");
    }
    else
    {
        curr=curr->prev;
        display_curr();
        printf("\n");
        display_all();
    }
}





