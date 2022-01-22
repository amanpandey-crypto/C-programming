//header file to merge two sorted doubly linked list and sort the merged list
#include "msm19b040_listset.h"

struct node *merge(struct node *l1,struct node *l2,struct node *l3)
{
    l3 = l1;
    temp=l3;
    while(temp->next!=NULL)  //traversing through the list 
    {
        temp=temp->next;
    }
    temp->next=l2;
    l2->prev=temp;
    l3 = sort(l3);
    return l3;
}

//main program
int main()
{
    struct node *l1=NULL,*l2=NULL,*l3=NULL;  //three list should be initialised to NULL
    int s1,s2;
    printf("\nEnter the size(list1): ");
    scanf("%d",&s1);
    l1 = create(l1,s1);  //creating list1
    l1 = sort(l1);       //sorting list1
    printf("\nAfter sorting(list1):");
    display(l1);
    printf("\nEnter the size(list2): ");
    scanf("%d",&s2);
    l2 = create(l2,s2);     //creating list2
    l2 = sort(l2);          //sorting list2
    printf("\nAfter sorting(list2):");
    display(l2);
    l3=merge(l1,l2,l3);    //merging list using merge function
    printf("\nSorted Merge list(list1+list2):");
    display(l3);  //displaying the final sorted merge list
    return 0;
}