#include<stdio.h>
#include<stdlib.h>

#define SIZE 10  //declaring size of the queue


//structure of the queue
struct cqueue
{
	int front,rear;
	int CQarr[SIZE];
	void (*enqueue)(int,struct cqueue*);
	void (*display)(struct cqueue*);
	int (*dequeue)(struct cqueue*);
};


//function to to enqueue operation
void enqueue(int num, struct cqueue *cqu)
{
    if((cqu->rear==SIZE-1)&&(cqu->front==0))               //checking the queue is full or not
    {
        printf("The circular queue is full.\n");
        exit(0);
    }
    else
    {
        if(cqu->front==-1)   //if queue is empty then initialising the front to index 0
        {
            cqu->front=0;
        }
        cqu->rear=(cqu->rear+1)%SIZE;
        cqu->CQarr[cqu->rear]=num;
    }
    
}

//functions to do dequeue operations
int dequeue(struct cqueue *cqu)
{
    if(cqu->front==-1)         // checking the queue is empty or not.
    {
        printf("The queue is empty.\n");
        exit(0);
    }
    else
    {
        int num=cqu->CQarr[cqu->front];
        if(cqu->rear==cqu->front)
        {
            cqu->rear=-1;
            cqu->front--;
        }
        else
        {
            cqu->front=(cqu->front+1)%SIZE;
        }
        return num;
    }
}


//function to display the queue
void display(struct cqueue *cqu)
{
    if(cqu->front==-1)
    {
        printf("The queue is empty.\n");
    }
    else
    {
        for(int i=cqu->front; i <= cqu->rear; i++)
        {
            printf("%d ",cqu->CQarr[i]);
        }
	    printf("\n");   
    }
}