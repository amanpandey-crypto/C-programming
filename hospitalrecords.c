#include<stdio.h>
#include<stdlib.h>
struct heap{
 int* a; int cap,cur;};
 
void swap(int a[],int i,int j){
 a[i]+=a[j];
 a[j]=a[i]-a[j]; a[i]-=a[j];}
 
void heapify_min(struct heap* p,int f){ //f is node to delete
    int j=f;
    while(j>=f){
    int i=j;
    while(1){int c=2*i+1;
        if(2*i+1>p->cur-1) break;
        if(2*i+1<=p->cur-1&&2*i+2>p->cur-1) {
        if(p->a[i]>p->a[c]) {swap(p->a,i,c); i=c;}
        break;}
        if(p->a[2*i+1]<p->a[2*i+2]){c=2*i+1;} else c=2*i+2;
        if(p->a[i]>p->a[c]) {swap(p->a,i,c); i=c;}
        else break;}
    j--;}}
 
struct heap* heap(int cap){
    struct heap* p=(struct heap*)malloc(sizeof(struct heap));
    p->a=(int*)malloc(sizeof(int)*cap);
    p->cap=cap;
    p->cur=0;
    return(p);}
 
int delete_acc(struct heap* p,int id){
    if(p->cur==0) {printf("No patients admitted currently\n"); return(1);}
    int i=0;
    while(i<p->cur){if(p->a[i]==id) break; i++;}
    if(i==p->cur){printf("No such id of patient present currently\n"); return(1);}
    else{
    swap(p->a,i,p->cur-1);
    p->cur--;
    heapify_min(p,i);
    return(p->a[p->cur]);}}
 
void insert_min(struct heap* p,int data){
    if(p->cap<p->cur+1) {printf("Cannot admit more patient, max capacity reached\n"); return;}
    p->a[p->cur]=data;
    int i=p->cur,j=(i-1)/2;
    while(j>=0){
    if(p->a[j]>p->a[i]) {swap(p->a,i,j); i=j; j=(j-1)/2;}
    else break;}
p->cur++;}
 
void search(struct heap* p,int data){
    int i=0;
    while(i<p->cur){if(p->a[i]==data) {printf("Patient record is active\n"); return;} i++;}
    printf("Patient record is NOT active\n"); return;}
 
void print(struct heap* p){
    int i=0;
    if(p->cur==0) {printf("No patients currently recorded\n"); return;}
    while(i<p->cur){printf("%d ",p->a[i]); i++;}
    printf("\n");}
 
int main(){
    int n;
    printf("Enter maximum capacity of heap");
    scanf(" %d",&n);
    struct heap* p=heap(n);
    int inp,temp,id;
    printf ("Possible operations :\n");
    printf ("Press 1 to insert patient id \n");
    printf ("Press 2 to delete patient id\n");
    printf ("Press 3 to display all records\n");
    printf ("Press 4 to Search a patient record\n");
    printf ("Press 5 to EXIT \n");
    while (1){
    printf ("Enter choice: ");
    scanf(" %d", &inp);
    switch (inp)
    {case 1:printf ("Enter patient Id \n");
    scanf(" %d", &id);
    insert_min(p,id); printf("Record: "); print(p); break;
    case 2:printf ("Enter patient to be discharged\n");
    scanf(" %d", &id);
    delete_acc(p,id);printf("Record: "); print(p); break;
    case 3:printf("The available records are: "); print(p); break;
    case 4:printf ("Enter record to be searched \n");
    scanf(" %d", &id);
    search(p,id); break;
    case 5: exit(1); break;
    default: printf("Enter valid choice\n");}}
    return(0);
}