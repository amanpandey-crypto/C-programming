//Program to do queue operations(enqueue & dequeue)

#include<stdio.h>
#include<stdlib.h>

#define SIZE 5  //declaring size of the queue


//structure of the queue
struct cqueue
{
	int front,rear;
	int CQarr[SIZE];
	void (*enqueue)(int,struct cqueue*);
	void (*display)(struct cqueue*);
	void (*dequeue)(struct cqueue*);
};
void enqueue(int,struct cqueue*);
void display(struct cqueue*);
void dequeue(struct cqueue*);



//main program
int main()
{
    int num,choice;
    struct cqueue cqu;
    cqu.enqueue=enqueue;
    cqu.display=display;
    cqu.dequeue=dequeue;
    cqu.front=-1;          //initialising front and rear to -1
    cqu.rear=-1;
    printf ("Choose operations :\n");    //operations to choose
    while (1)
    {
        printf ("  1. Insert        \n");
        printf ("  2. Delete        \n");
        printf ("  3. Display       \n");
        printf ("  4. EXIT          \n");
 
        printf ("Enter your choice:");
        scanf    ("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter a number to be pushed:");
            scanf("%d", &num);
            cqu.enqueue(num,&cqu);
            break;
        case 2:
            cqu.dequeue(&cqu);
            break;
        case 3:
            cqu.display(&cqu);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid Input, try again!!\n");
        }
    }
}


//function to to enqueue operation
void enqueue(int num, struct cqueue *cqu)
{
    if(((cqu->rear==SIZE-1)&&(cqu->front==0))||(cqu->front==cqu->rear+1))               //checking the queue is full or not
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
void dequeue(struct cqueue *cqu)
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
            cqu->front=-1;
        }
        else
        {
            cqu->front=(cqu->front+1)%SIZE;
            printf("The item deleted is %d :\n",num);
        }
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
        printf("After doing queue operations, queue is :\n");
        if(cqu->front<=cqu->rear)   // checking 
        {
            for(int i=cqu->front; i <= cqu->rear; i++)
            {
                printf("%d ",cqu->CQarr[i]);
            }
        }
        else
        {
            for(int i=cqu->rear; i <= cqu->front; i++)
            {
                printf("%d ",cqu->CQarr[i]);
            }
        }
	    printf("\n");   
    }
}