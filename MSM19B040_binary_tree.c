//Program to implement binary tree insertion, finding heights and different transversal

#include<stdio.h>
#include<stdlib.h> 

//defining the structure 
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
} node;

//structure to create a node 
node *create()
{
	int data;
    node* t;
	printf("Enter data(-1 for no data): ");
	scanf("%d",&data);

	if(data==-1)
		return NULL;

	t=(struct node*)malloc(sizeof(struct node));
	t->data=data;

	printf("Enter left child of %d:\n",data);
	t->left=create();

	printf("Enter right child of %d:\n",data);
	t->right=create();
	return t;
}
 
//function for preorder traversal
void Preorder(node *t)		//address of root node is passed in t
{
	if(t!=NULL)
	{
		printf("%d ",t->data);		
		Preorder(t->left);		//traversal on left subtree
		Preorder(t->right);		//traversal om right subtree
	}
}

//function for inorder traversal
void Inorder(node *t)
{
    if(t!=NULL)
	{
        Inorder(t->left);
		printf("%d ",t->data);
		Inorder(t->right);
    }
    
}

//function for postorder traversal
void Postorder(node *t)
{
    if(t!=NULL)
	{
        Postorder(t->left);
		Postorder(t->right);
		printf("%d ",t->data);
    }
    
}

//finding height of the node
int nodeheight(node* t, int key,int h)
{
    if(t==NULL)
	{
        return 0;
    }
    if(t->data == key)
	{
        return h;
    }
    int level = nodeheight(t->left, key, h+1);
    if(level!=0){
        return level;
    }
    level = nodeheight(t->right, key, h+1);
    if(level!=0)
	{
        return level;
    }
    return -1;
}

//function to find maximum of two
int max(int m, int n)
{
	return (m)>(n)?(m):(n);
}
//finding the height of the tree
int treeheight(node *t)
{
    if(t == NULL)
        return -1;
    else
        return (1 + max(treeheight(t->left), treeheight(t->right)));
}

//main function
int main()
{
    int i,choice;
    struct node *t = NULL;
    while(1)
	{
		printf("\n--Menu operations--");
        printf("\n 1. Create Tree\n 2. Inorder Traversal\n 3. Preorder Traversal \n 4. Postorder Traversal\n 5. Tree height\n 6. Node height");
		printf("\n 7. Exit the program ");
		printf("\n Enter Your choice: ");
		scanf("%d", &choice);
        switch(choice)
		{
            case 1 :
                    if( t == NULL )
					{
                        t = create();
                    }
                    else
					{
                        printf("\n Already there.");   //tree created already.
                    }
                    break;
            case 2 :
                    if(t==NULL)
					{
                        printf("Empty!!\n");
                    }
                    else
					{
                        printf("\nAfter Inorder Traversal: ");
                        Inorder(t);
                    }
                    break;
            case 3 :
                    if(t==NULL)
					{
                        printf("Empty!!\n");
                    }
                    else
					{
                        printf("\nAfter Preorder Traversal: ");
                        Preorder(t);
                    }
                    break;
            case 4 :
                    if(t==NULL)
					{
                        printf("Empty!!\n");
                    }
                    else
					{
                        printf("\nAfter Postorder Traversal: ");
                        Postorder(t);
                    }
                    break;
            case 5 :
                    printf("\n Tree height(initial height =0): ");    
                    printf("%d",treeheight(t));
                    break;
            case 6 :
                    printf("\nEnter value of the node: ");
                    scanf("%d",&i);
                    if(nodeheight(t,i,0)!=-1)
					{
                        printf("\nNode Height(initial height =0): ");  
                        printf(" %d",nodeheight(t,i,0));
                    }
                    else
					{
                        printf("%d node is not there\n",i);
                    }
                    break;
            case 7: printf("Exiting the program");
			        exit(0);
		    default: printf("\nInvalid input, try again!!!");
        }
    }
	return 0;
}
