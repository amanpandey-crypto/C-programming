struct node
{
    int data ;
    struct node *link;
} ;

struct deque
{
    struct node *front;
    struct node *rear;
};
void EnqueueRear(struct deque *p, int item)
{
    p ->  front = p -> rear = NULL ;
    struct node *temp ;
    temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = item ;
    temp -> link = NULL ;

    if ( p -> front == NULL )
        p -> front = temp ;
    else
        p -> rear -> link = temp ;
    p -> rear = temp ;
}
void Enqueuefront(struct deque *p, int value )
{
    p ->  front = p -> rear = NULL ;
    struct node *temp ;
    int *q ;
    temp = (struct node *)malloc(sizeof(struct node ));
    temp -> data = value ;
    temp -> link = NULL ;

    if ( p -> front == NULL )
        p -> front = p -> rear = temp ;
    else
    {
        temp -> link = p -> front ;
        p -> front = temp ;
    }
}
int DequeueFront ( struct deque *p )
{
    p ->  front = p -> rear = NULL ;
    struct node *temp = p -> front ;
    int item ;
    if ( temp == NULL )
    {
        printf ( "\nQueue is empty." ) ;
        return 0 ;
    }
    else
    {
        temp = p -> front ;
        item = temp -> data ;
        p -> front = temp -> link ;
        free ( temp ) ;

        if ( temp == NULL )
            p -> rear = NULL ;
        return ( item ) ;
    }
}
int DequeueRear ( struct deque *p )
{
    p->front = p->rear = NULL ;
    struct node *temp , *rleft, *q ;
    int item ;
    temp = p -> front ;
    if ( p -> rear == NULL )
    {
        printf ( "\nQueue is empty." ) ;
        return 0 ;
    }
    else
    {
        while ( temp != p -> rear )
        {
            rleft = temp ;
            temp = temp -> link ;
        }
        q = p -> rear ;
        item = q -> data ;
        free ( q ) ;
        p -> rear = rleft ;
        p -> rear -> link = NULL ;
        if ( p -> rear == NULL )
            p -> front = NULL ;
        return ( item ) ;
    }
}