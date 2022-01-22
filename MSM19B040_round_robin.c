// Program to implement the round robin algorithm

#include "Circ_queue.h"

int main()
{
    struct cqueue* qu =(struct cqueue*)malloc(sizeof(struct cqueue));
    qu->front=0;
    qu->rear=-1;
    int process, cpu_time, step=1;
    printf("\nEnter no of processes :");
    scanf("%d",&process);
    printf("\nEnter time allotted for each processes :\n");
    for(int i=0; i<process; i++)
    {
        printf("P%d =",i+1);
        int num;
        scanf("%d",&num);
        enqueue(num,qu);
    }
    printf("\nEnter Cpu Share time :");
    scanf("%d",&cpu_time);
    printf("\nThe CPU queue after enqueuing all the process :");
    display(qu);
    while(process)
    {
        printf("\nSwitch %d\n",step++);
        int deq = dequeue(qu);
        printf("%d Dequeued\n",deq);
        if(deq>=cpu_time)
        {
            printf("%d units executed\n",cpu_time);
            if(deq-cpu_time>0)
            {
                enqueue(deq-cpu_time, qu);
                printf("Enqueue %d\n",deq-cpu_time);
                printf("Remaining: ");
                display(qu);
            }
            else
            {
                printf("0 is not Enqueued and that process is completed\n");
                process--;
                printf("Remaining: ");
                display(qu);
            }
        }
        else    
        {
            if(process>1)
            {            
                printf("%d units executed\n",deq);
                printf("0 is not Enqueued and that process is completed\n");
                process--;
                printf("Remaining: ");
                display(qu);
            }
            else
            {
                printf("%d units executed\n",deq);
                printf("0 is not Enqueued and that process is completed\n");
                printf("All Process Completed\n");
                process=0;
            }             
        }    
    }
    printf("\nCPU Returning to Idle State. Stopping Program.");
    return 0;
}
    