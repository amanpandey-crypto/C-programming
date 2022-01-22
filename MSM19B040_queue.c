//Program to do queue operations(enqueue & dequeue)

#include<stdio.h>
#include<stdlib.h>

#define SIZE 5  //declaring size of the queue


//structure of the queue
struct queue
{
	int front,rear;
	int Qarr[SIZE];
	void (*enqueue)(int,struct queue*);
	void (*display)(struct queue*);
	void (*dequeue)(struct queue*);
};
void enqueue(int,struct queue*);
void display(struct queue*);
void dequeue(struct queue*);



//main program
int main()
{
    int num,choice;
    struct queue qu;
    qu.enqueue=enqueue;
    qu.display=display;
    qu.dequeue=dequeue;
    qu.front=-1;          //initialising front and rear to -1
    qu.rear=-1;
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
            qu.enqueue(num,&qu);
            break;
        case 2:
            qu.dequeue(&qu);
            break;
        case 3:
            qu.display(&qu);
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
void enqueue(int num, struct queue *qu)
{
    if(qu->rear==SIZE-1)               //checking the queue is full or not
    {
        printf("The queue is full.\n");
        exit(0);
    }
    else
    {
        if((qu->rear==-1)&&(qu->front==-1))   //if queue is empty then initialising the front to index 0
        {
            qu->front=0;
        }
        qu->rear+=1;
        qu->Qarr[qu->rear]=num;
    }
    
}

//functions to do dequeue operations
void dequeue(struct queue *qu)
{
    if(qu->front==-1)         // checking the queue is empty or not.
    {
        printf("The queue is empty.\n");
        exit(0);
    }
    else
    {
        int num=qu->Qarr[qu->front];
        if(qu->rear==qu->front)
        {
            qu->rear=-1;
            qu->front=-1;
        }
        else
        {
            qu->front+=1;
            printf("The item deleted is %d :",num);
        }
    }
}


//function to display the queue
void display(struct queue *qu)
{
    if(qu->front==-1)
    {
        printf("The queue is empty\n");
    }
    else
    {
        printf("After doing queue operations, queue is :\n");
        for(int i=qu->front; i <= qu->rear; i++)
        {
            printf("%d\n",qu->Qarr[i]);
        }
	    printf("\n");   
    }
}