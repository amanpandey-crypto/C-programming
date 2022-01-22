//program to implement circular linked list


#include<stdio.h>
#include<stdlib.h>


// structure for a node 
struct node 
{ 
    int data; 
    struct node* next; 
};

struct node *ins_empt(struct node *last, int data) 
{ 
    if (last != NULL) //check if list is empty
    {
        return last;
    } 

    struct node *temp =(struct node* )malloc(sizeof(struct node)); //temporary node using DMA
    temp -> data = data; 
    last = temp;  
    last -> next = last; 
    return last; 
} 

struct node *ins_beg(struct node *last, int data) 
{ 
    if (last == NULL)
    { 
        return ins_empt(last, data); 
    }
    struct node *temp =(struct node *)malloc(sizeof(struct node)); 
    temp -> data = data; 
    temp -> next = last -> next; 
    last -> next = temp; 
    return last; 
}

struct node *ins_mid(struct node *last, int data, int key) 
{ 
    if (last == NULL) 
        return NULL; 
  
    struct node *temp, *p; 
    p=last->next; 
    do
    { 
        if (p ->data == key) 
        { 
            temp = (struct node *)malloc(sizeof(struct node)); 
            temp -> data = data; 
            temp -> next = p -> next; 
            p -> next = temp; 
  
            if (p == last) 
                last = temp; 
            return last; 
        } 
        p = p -> next; 
    }  while(p != last -> next);  
    return last; 
  
} 

//function to insert element in the end
struct node *ins_end(struct node *last, int data) 
{ 
    if (last == NULL) 
        return ins_empt(last, data); 
      
    struct node *temp =  
        (struct node *)malloc(sizeof(struct node)); 
  
    temp -> data = data; 
    temp -> next = last -> next; 
    last -> next = temp; 
    last = temp; 
  
    return last; 
}



// Function to display data in the list 
void display(struct node* head) 
{ 
    struct node* current = head; 
    if (head == NULL)//check if list is empty
    { 
        printf("\nNULL\n"); 
        return; 
    }  
    else { 
        do 
        { 
            printf("%d ", current->data); 
            current = current->next; 
        } while (current != head); 
    } 
} 

// Function return number of nodes present in list 
int countnode(struct node* head) 
{ 
    struct node* current = head; 
    int listcount = 0; 
    if (head == NULL)//check if list is empty count=0
    { 
        return 0; 
    } 

    else { 
        do
        { 
            current = current->next; 
            listcount++; 
        } while (current != head); 
    } 
    return listcount; 
} 

// Function delete First node of Circular Linked List 
void Deletebeg(struct node** head) 
{ 
    struct node *previous = *head, *next = *head; 

    // check list have any node 
    // if not then return 
    if (*head == NULL) { 
        printf("\nList is empty\n"); 
        return; 
    } 
    if (previous->next == previous) 
    { 
        *head = NULL; 
        return; 
    } 

    while (previous->next != *head) { 

        previous = previous->next; 
        next = previous->next; 
    } 
    previous->next = next->next;  
    *head = previous->next; 
    free(next);  
} 

// Function to delete last node of 
// Circular Linked List 
void Deleteend(struct node** head) 
{ 
    struct node *current = *head, *temp = *head, *previous; 

    // check if list doesn't have any node 
    // if not then return 
    if (*head == NULL) { 
        printf("\nList is empty\n"); 

    } 

 
    if (current->next == current) { 
        *head = NULL; 
    } 

    // move first node to last 
    // previous 
    while (current->next != *head) { 
        previous = current; 
        current = current->next; 
    } 

    previous->next = current->next; 
    *head = previous->next; 
    free(current); 

    return; 
} 

// Function delete node at a given poisition 
// of Circular Linked List 
void Deletemid(struct node** head, int index) 
{ 
    // Find length of list 
    int len = countnode(*head); 
    int listcount = 1; 
    struct node *previous = *head, *next = *head; 

    // check list have any node 
    // if not then return 
    if (*head == NULL) { 
        printf("\nDelete Last List is empty\n"); 
        return; 
    } 

    // given index is in list or not 
    if (index >= len || index < 0) { 
        printf("\nIndex is not Found\n"); 
        return; 
    } 

    // delete first node 
    if (index == 0) { 
        Deletebeg(head); 
        return; 
    }  
    while (len > 0) { 

        // if index found delete that node 
        if (index == listcount) { 
            previous->next = next->next; 
            free(next);  
        } 
        previous = previous->next; 
        next = previous->next; 
        len--; 
        listcount++; 
    } 
    return; 
} 

//main program 
int main() 
{ 
    int choice,value,pos ;
    struct node* head = NULL; 
    printf("\n--OPERATIONS--\n");
    
  
    while(1)
    {
            printf("\nEnter your choice: \t 1. InsertB \t2. InsertE \t 3. InsertM \t 4. DeleteB \t 5. DeleteE \t 6. DeleteM \t 7. Display \t8. Exit \n");
            scanf("%d",&choice);
            switch(choice){
            case 1: printf("\nEnter the element to insert at the beginning\n");
            scanf("%d",&value);
                head = ins_beg(head, value);
                break;
            case 2: 
                printf("\nEnter the element to insert at the end\n");
                scanf("%d",&value);
                head = ins_end(head, 8);
                break;
            case 3: 
                printf("\nEnter position after which you want to insert \n");
                scanf("%d",&pos);
                printf("\nEnter the element to insert\n");
                scanf("%d",&value);
                head= ins_mid(head, pos, value);
                break;
            
            case 4: 
                Deletebeg(&head);
                break;
            case 5:
                Deleteend(&head);
                break;
            case 6: 
                scanf("%d",&pos);
                Deletemid(&head, pos);
                break;
            case 7: 
                display(head);
                break;
            case 8: exit(0);
        } 
    }
   

    return 0; 
} 
