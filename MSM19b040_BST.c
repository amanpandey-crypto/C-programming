//Program to implement binary search tree 

#include<stdio.h>
#include<stdlib.h>

//structure of a node
struct node 
{
    int data;
    struct node *left;
    struct node *right;
}*rt= NULL,*Newnode,*curr;

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
int add(int val)
{
	// create a node
	Newnode = CreatedNode(val);
	if (rt == NULL)
	{
		rt = Newnode;
	}
    else
	{
		curr = rt;
		while (1)
		{					
            if (Newnode->data < curr->data)
            {
                if(curr->left == NULL)
                {
                    curr->left = Newnode;
                    break;
                }
                curr = curr->left; // move pointer left           
            }
            else if (Newnode->data > curr->data)
            {
                if(curr->right == NULL) // if left child is NULL
                {
                    curr->right = Newnode;
                    break;
                }
                curr = curr->right; // move pointer right
			}
        }	
	}	
}

struct node * min(struct node *rt)
{
    if(!rt)
    {
        return NULL;
    }
    while(rt->left) rt = rt->left;
    return rt;
}

//function to find inorder successor
struct node *InSuc(struct node *rt, struct node *node)
{
    struct node *succ = NULL;
    struct node *curr  = rt;
    if(!rt)
    {
        return NULL;
    }
    while(curr->data != node->data) 
    {
        if(curr->data > node->data)
        {
            succ = curr;
            curr= curr->left;
        }
        else
            curr = curr->right;
    }
    if(curr && curr->right)
    {
        succ = min(curr->right);
    } 
    return succ;
}

//finding the max node function
struct node *max(struct node *rt)
{
    if(!rt)
    {
        return NULL;
    }
    while(rt->right) rt = rt->right;
    return rt;
}

//function to find inorder predecessor
struct node *InPred(struct node *rt, int key)
{
  
    struct node *pred   = NULL;
    struct node *curr = rt; 
    if(!rt)
    {
        return NULL;
    }
    while(curr && curr->data != key) 
    {
        if(curr->data >key)
        {
            curr= curr->left;
        }
        else
        {
            pred = curr;
            curr = curr->right;
        }
    }
    if(curr && curr->left)
    {
        pred = max(curr->left);
    }
    return pred;
}

//function to delete node with 3 cases
struct node* delete(struct node* rt, int key) 
{ 
    if (rt == NULL) 
    {
        return rt; 
    }
    if (key < rt->data)
    { 
        rt->left = delete(rt->left, key);
    }
    else if (key > rt->data) 
    {
        rt->right = delete(rt->right, key);
    }
    else
    { 
        //for having one child
        if (rt->left == NULL) 
        { 
            struct node *temp = rt->right; 
            free(rt);
            return temp; 
        } 
        else if (rt->right == NULL) 
        { 
            struct node *temp = rt->left; 
            free(rt);  
            return temp; 
        } 
        // for having two child
        struct node* temp = min(rt->right); 
        rt->data = temp->data; 
        rt->right = delete(rt->right, temp->data);
    } 
    return rt; 
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


//main function
int main()
{
    int i,choice;
    struct node *rt = NULL;
    while(1)
	{
		printf("\n--Operations--\n 1. Insert element in the tree\t 2. Deletion\t 3. Inorder traversal\t");
        printf("\n 4. Inorder Succesor");
        printf("\t 5. Inorder predecessor");
        printf("\t 6. Exit ");
		printf("\n Enter Your choice:");
		scanf("%d", &choice);
        int key,item,value;
        switch(choice)
        {
            case 1 :
                printf("Enter the value to insert :");
                scanf("%d", &value);
                add(value);
                break;
            case 2 :
                printf("Enter the value to delete :");
                scanf("%d", &item);
                rt = delete(rt,item);
                printf("%d deleted.",item); 
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
                break;
            case 5 :
                printf("Enter the key to get successor :");
                scanf("%d", &key);
                struct node *pred=InPred(rt, key);
                break;
            case 6: 
                printf("Exiting the program");
                exit(0);
            default: 
                printf("Invalid choice, need to enter again!!");
        }
    }
	return 0;
}