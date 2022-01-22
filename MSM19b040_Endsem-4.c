#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;};
struct node* create(int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    return(temp);}
void add(struct node*i1,struct node* i2,struct node** a){
    (*a)=create(i1->data+i2->data);
    i1=i1->next; i2=i2->next;
    while(i1!=NULL){
        (*a)->next=create(i1->data+i2->data);
        (*a)=(*a)->next; i1=i1->next; i2=i2->next;}
}
void sub(struct node*i1,struct node* i2,struct node** s){
    (*s)=create(i1->data-i2->data);
    i1=i1->next; i2=i2->next;
    while(i1!=NULL){
        (*s)->next=create(i1->data-i2->data);
        (*s)=(*s)->next; i1=i1->next; i2=i2->next;}
}
void mul(struct node*i1,struct node* i2,struct node** m){
    (*m)=create(i1->data*i2->data);
    i1=i1->next; i2=i2->next;
    while(i1!=NULL){
        (*m)->next=create(i1->data*i2->data);
        (*m)=(*m)->next; i1=i1->next; i2=i2->next;}
}
void divi(struct node*i1,struct node* i2,struct node** d){
    (*d)=create(i1->data/i2->data);
    i1=i1->next; i2=i2->next;
    while(i1!=NULL){
        (*d)->next=create(i1->data/i2->data);
        (*d)=(*d)->next; i1=i1->next; i2=i2->next;}}
 
void printlist(struct node* a){
    while(a!=NULL) {printf("%d ",a->data);}
    printf("\n");
}
//main function
int main()
{
    int n,m,data;
    struct node* i1=NULL,*i2=NULL,*temp,*a,*d,*s,*mi;
    printf("Enter number of nodes to insert in list-1 and list-2\n");
    scanf(" %d %d",&n,&m);
    temp=i1;
    printf("Enter all %d values of list-1\n",n);
    scanf(" %d",&data);
    temp=create(data);
    for(int i=1;i<n;i++)
    {
        scanf(" %d",&data);
        temp->next=create(data);
        temp=temp->next;
    }
    temp=i2;
    printf("Enter all %d values of list-2\n",m);
    scanf(" %d",&data);
    temp=create(data);
    for(int i=1;i<m;i++)
    {
        scanf(" %d",&data);
        temp->next=create(data);
        temp=temp->next;
    }
    int diff=0;
    if(n<m){
        diff=m-n;
        temp=i1;
        while(temp->next!=NULL) temp=temp->next;
        while(diff--)
        {
            temp->next=create(0); temp=temp->next;
            }}
    else if(n>m){
        diff=n-m;
        temp=i2;
        while(temp->next!=NULL) temp=temp->next;
        while(diff--){temp->next=create(0); temp=temp->next;}}
 
    add(i1,i2,&a);
    sub(i1,i2,&s);
    mul(i1,i2,&mi);
    printf("for division padded list is numerator\n");
    if(n>m) divi(i2,i1,&d);
    else divi(i1,i2,&d);
    printf("Add: "); printlist(a);
    printf("Sub: "); printlist(s);
    printf("Mul: "); printlist(mi);
    printf("Div: "); printlist(d);
    return(0);
}