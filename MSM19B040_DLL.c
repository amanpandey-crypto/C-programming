//program to implement doubly linked list

#include<stdio.h>
#include<stdlib.h>

//structure to define a node
struct node
{
    struct node *prev;
    int data;
    struct node *next;
} *head = NULL,*newNode,*temp;
int listcount=0;


//displaying the list
void display()
{
    temp=head;
    if(head==NULL){
        printf("The list is empty\n");
    }
    else
    {
        printf("Data:");
        while(temp!=NULL)
        {   
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
    listcount+=0;
}

//function to insert a node in the beginning
void Insbeg()
{
    newNode = (struct node *)malloc(sizeof(struct node));  //allocating memory to the new node
    printf("Enter data: ");
    scanf("%d",&newNode->data);
    newNode->next = NULL;
    newNode->prev = NULL;
    if(head==NULL)     //check whether the list is empty or not
    {
        head = newNode;
        printf("%d Inserted.\n",newNode->data);
        display();
    }
    else
    {
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
        printf("%d Inserted.\n",newNode->data);
        display();
    }
    listcount++;
}

//function to count the no. of node in the list
int len_list()
{
    return listcount;
}


//function to insert a node in the end
void Insend()
{
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&newNode->data);
    newNode->next = NULL;
    newNode->prev = NULL;
    if(head==NULL)
    {
        head=newNode;
        printf("%d Inserted.\n",newNode->data);
        display();
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
        printf("%d Inserted.\n",newNode->data);
        display();
    }
    listcount++;
}

//function to insert node in middle of the list
void Insmid()
{
    int length = len_list();
    if(length<2)   //checking the condition of middle element
    {
        printf("Atleast two element should be there.\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data : ");
        scanf("%d",&newNode->data);
        newNode->next = NULL;
        newNode->prev = NULL;
        temp=head;
        length =(length/2)+1;
        int i=1;
        while(i<length-1)
        {
            temp=temp->next;
            i++;
        }
        newNode->prev=temp;
        newNode->next=temp->next;
        temp->next->prev=newNode;
        temp->next=newNode;
        printf("%d Inserted.\n",newNode->data);
        display();
    }
    listcount++;
}

//function to insert at a given position
void Inspos()
{
    int pos;
    printf("Enter position where to be inserted: ");
    scanf("%d",&pos);
    if(pos==1)
    {
        Insbeg();
    }
    else if(pos<=listcount && pos>1)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data : ");
        scanf("%d",&newNode->data);
        newNode->next = NULL;
        newNode->prev = NULL;
        temp=head;
        int i=1;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newNode->prev=temp;
        newNode->next=temp->next;
        temp->next->prev=newNode;
        temp->next=newNode;
        listcount++;
        printf("%d Inserted.\n",newNode->data);
        display();
    }
    else if(pos==listcount+1)
    {
        Insend();
    }
    else if(pos-listcount>1)
    {
        printf("Invalid Position\n");
    }
}

//check whether the list is empty or not
void isEmpty()
{
    if(head==NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        printf("Not empty!\n");
        printf("Elements present in the list: ");
        display();
    }
}

//funcction to delete from the beginning
void Delbeg()
{
    int data;
    if(head==NULL)
    {
        printf("The list is empty\n");
    }
    else if(listcount==1)
    {
        temp=head;
        data=temp->data;
        head=NULL;
        free(temp);
        listcount--;
        printf("%d removed from the list\n",data);
    }
    else
    {
        temp=head;
        data=temp->data;
        head=head->next;
        head->prev=NULL;
        free(temp);
        listcount--;
        printf("%d removed from the list\n",data);
    }
}

//function to delete from the end
void Delend()
{
    int data;
    if(head==NULL)
    {
        printf("The list is empty\n");
    }
    else if(listcount==1){
        temp=head;
        data=temp->data;
        head=NULL;
        free(temp);
        listcount--;
        printf("%d removed from the list\n",data);
    }
    else{
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        data=temp->data;
        temp->prev->next=NULL;
        free(temp);
        listcount--;
        printf("%d removed from the list\n",data);
    }
}


//function to delete from the given position
void Delpos(int pos)
{
    int data;
    if(pos==1) Delbeg();
    else if(pos==listcount) Delend();
    else if(pos>1 && pos<listcount)
    {
        temp=head;
        int i=1;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        data=temp->data;
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
        free(temp);
        listcount--;
        printf("%d removed from the list\n",data);
    }
    else
    {
        printf("Invalid Position!!!\n");
    }
}

//function to delete from the middle of the list
void Delmid()
{
    int data;
    int length = len_list();
    if(length<=2){
        printf("No mid element is present in the list\n");
    }
    else if(length%2==0 && length>2)
    {
        Delpos(length/2);
    }
    else if(length%2!=0 && length>2)
    {
        Delpos(length/2+1);
    }
}

//function to search for a node in the list
void search()
{
    int node_data;
    printf("\nEnter the node data:");
    scanf("%d",&node_data);
    temp=head;
    int i=1;
    if(head==NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        while(temp!=NULL)
        {
            if(temp->data==node_data)
            {
                break;
            }
            else
            {
                temp=temp->next;
            }
            i++;
        }
        if(i>listcount)
        {
            printf("%d is not there in the list.\n",node_data);
        }
        else
        {
            printf("%d found at position %d\n",node_data,i);
        }
    }
}


//function to modify given node
void modify()
{
    int pos,newData;
    printf("Enter position of the node: ");
    scanf("%d",&pos);
    if(head==NULL)
    {
        printf("The list is empty\n");
    }
    else if(pos>=1 && pos<=listcount)
    {
        printf("Enter new data");
        scanf("%d",&newData);
        temp=head;
        int i=1;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        temp->data=newData;
        printf("After Modification, the list will be:\n");
        display();
    }
}

//menu driven main program
int main()
{
    int choice,position;
    printf("------Menu------\n");
    printf("1. Insert a node in beginning\n2. Insert a node in end\n3. Insert a node at specific position\n4. Insert a node in the middle of list\n");
    printf("5. Display the list\n");
    printf("6. Delete a node from the beginning\n7. Delete a node from the end\n8. Delete a node from a specifc position\n9. Delete a node from middle of the list\n");
    printf("10. Check the list is empty or not\n");
    printf("11. Length of the list\n");
    printf("12. Modify the node\n");
    printf("13. Search for a node\n");
    printf("14. Exit the program\n ");
    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: 
                Insbeg();
                break;
            case 2: 
                Insend();
                break;
            case 3: 
                Inspos();
                break;
            case 4: 
                Insmid();
                break;
            case 5:  
                display();
                break;
            case 6: 
                Delbeg();
                break;
            case 7: 
                Delend();
                break;
            case 8: 
                printf("\nEnter position: ");
                scanf("%d",&position);
                Delpos(position);
                break;
            case 9:  
                Delmid();
                break;
            case 10: 
                isEmpty();
                break;
            case 11: 
                printf("Length of the list is %d \n",len_list());
                break;
            case 12: 
                modify();
                break;
            case 13: 
                search();
                break;
            case 14: 
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice, try again!!");
                break;
        }
    }
    return 0;
}