#include<stdio.h>
#include<stdlib.h>
#define size 20
char names[30][20];
struct Queue{
    int front;
    int rear;
    int arr[size];
};
void enqueue(int i,struct Queue* st){
    if(st->front==0 && st->rear==size-1){
        printf("Overflow\n");
        return;}
    if(st->rear==(st->front-1)%size){
        printf("Overflow\n");
        return;}
    if(st->front==-1){
        st->front=0;st->rear=0;
        st->arr[st->rear]=i;
        return;}
        st->rear++;
        if(st->rear>size-1)st->rear=st->rear%size;
        st->arr[st->rear]=i;
}
void dequeue(struct Queue* st){
    if(st->front==-1)printf("Queue empty\n");
    else if(st->rear==st->front){
        st->front=-1;st->rear=-1;
    }
    else if(st->front==size-1)st->front=0;
    else st->front++;
}
void display(struct Queue* st){
    int z=st->front;
    if(st->front==-1){
        printf("Queue empty\n");
        return;
    }
    else {
        while(z!=-1){
            printf("%s ",names[st->arr[z]]);
            if(st->rear==z)z=-1;
    else if(z==size-1)z=0;
    else z++;
        }
        printf("\n");
    }
}
 
int main(){
    struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
    q->front=-1;q->rear=-1;
    int i;int k;int n;int m=0;int crr=0;
    while(1){
        printf("Select option:");
        printf("1.Add a player\n");
        printf("2.Eliminate a player\n");
        scanf("%d",&n);
        if(n==1){
            enqueue(m,q);
            printf("Enter a name\n");
            scanf("%s",names[m]);
            m++;crr++;
            display(q);
        }
        if(n==2){
            printf("Enter a stopping number:");
            scanf("%d",&k);
            int pos=(q->front+(k-1)%crr)%size;
            crr--;
            while(q->front!=pos){
                enqueue(q->arr[q->front],q);
                dequeue(q);
            }
            printf("(%s) is out\n",names[q->arr[q->front]]);
            dequeue(q);
            printf("The next round starts with (%s)\n",names[q->arr[q->front]]);
            printf("The remaining players are\n");
            display(q);
            if(crr==1){printf("Winner is (%s)",names[q->arr[q->front]]);exit(0);}
        }
 
    }
    return 0;
}