//Program to implement binary search tree 

#include<stdio.h>
#include<stdlib.h>

//structure of a node
struct node 
{
    int data;
    struct node *left;
    struct node *right;
}*Newnode,*curr;

//To create a node
struct node* CreatedNode(int item)
{
    Newnode = (struct node*)malloc(sizeof(struct node));
    Newnode->data = item;
    Newnode->left = NULL;
    Newnode->right = NULL;
    return Newnode;
}

//Function to create the Binary search tree.
struct node* Insert(struct node* rt,int data)
{
    Newnode = CreatedNode(data);
    if(rt==NULL)
    {
        rt = Newnode;
    }
    else
    {
        if(data < rt->data)
        {
            rt->left = Insert(rt->left,data);
        }
        else if(data > rt->data)
        {
            rt->right = Insert(rt->right,data);
        }
        else{
            printf("%d is can't be insert here",data);
        }
    }
}

//preorder transversal function
void Pre(struct node* rt)
{
    if(rt!= NULL)
    {
        printf("%d ",rt->data);
        Pre(rt->left);
        Pre(rt->right);
    }
}

//Inorder transversal function
void In(struct node* rt)
{
    if(rt != NULL)
    {
        In(rt->left);
        printf("%d ",rt->data);
        In(rt->right);
    }
}

//Postorder transversal function
void Post(struct node* rt)
{
    if(rt!=NULL)
    {
        Post(rt->left);
        Post(rt->right);
        printf("%d ",rt->data);
    }
}

//finding the min node function
int min(struct node* rt)
{
    curr = rt;
    while(curr->left!=NULL)       //doing till current left node is empty
    {
        curr = curr->left;
    }
    return curr->data;
}

//finding the max node function
int max(struct node* rt)
{
    curr = rt;
    while(curr->right!=NULL)    //doing till current right node is empty
    {
        curr = curr->right;
    }
    return curr->data;
}

//Searching for a node function
void Searchitem(struct node* t, int item)
{
    if(t==NULL)
    {
        printf("%d is not there",item);
    }
    else{
        if(t->data > item)
        {
            Searchitem(t->left,item);
        }
        else if(t->data < item)
        {
            Searchitem(t->right,item);
        }
        else
        {
            printf("%d is there",item);
        }
    }
}

//main function
int main()
{
    int i,choice;
    struct node *rt = NULL;
    while(1)
	{
		printf("\n--Operations--\n 1. Insert element in the tree\t 2. Preorder Traversal\t 3. Inorder Traversal\t 4. Postorder Traversal ");
        printf("\n 5. Minimum element in the tree");
        printf("\t 6. Maximum element in the tree");
        printf("\t 7. Search");
        printf("\t 8. Exit ");
		printf("\n Enter Your choice:");
		scanf("%d", &choice);
        int n,k,item;
        switch(choice)
        {
            case 1 :
                    if(rt==NULL)
                    {
                        printf("\nNo. of nodes:");  //no. of nodes for a binary search tree
                        scanf("%d",&n);
                        printf("\nEnter %d values: ", n);
                        for(int i=0; i<n; i++)
                        {
                            scanf("%d",&k);
                            rt = Insert(rt,k);
                        }
                    }
                    else
                    {
                        printf("\nAlready created!");
                    }
                    break;
            case 2 :
                if(rt==NULL)
                {
                    printf("Empty!\n");
                }
                else
                {
                    printf("\nAfter doing Preorder Traversal: ");
                    Pre(rt);                  
                }
                break;
            case 3 :
                if(rt==NULL)
                {
                    printf("Empty!!\n");
                }
                else
                {
                    printf("\nAfter doing Inorder Traversal: ");
                    In(rt);          
                }
                break;
            case 4 :
                if(rt==NULL)
                {
                    printf("Empty!\n");
                }
                else
                {
                    printf("\nAfter doing Postorder Traversal: ");
                    Post(rt);
                }
                break;
            case 5 :
                if(rt==NULL)
                {
                    printf("Empty!!\n");
                }
                else
                {
                    printf("\nMinimum node data:");
                    printf("%d",min(rt));   
                }
                break;
            case 6 :
                if(rt==NULL)
                {
                    printf("Empty!!\n");
                }
                else
                {
                    printf("\nMaximum node data:");
                    printf("%d",max(rt));       
                }
                break;
            case 7 :
                printf("Enter the data to search: ");
                scanf("%d",&item);
                Searchitem(rt,item);      
                break;
            case 8: 
                printf("Exiting the program");
                exit(0);
            default: 
                printf("Invalid choice, need to enter again!!");
        }
    }
	return 0;
}