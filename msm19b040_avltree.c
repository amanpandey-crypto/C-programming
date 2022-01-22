//program to implement avl tree insertion and deletion
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int key;
	struct node *left;
	struct node *right;
	int height;
};

int height(struct node *N)
{
	if (N == NULL)
    {
		return 0;
    }
	return N->height;
}
//maximum of two integer
int max(int num1, int num2)
{
	if(num1>num2)
    {
        return num1;
    }
    return num2;
}
//to create new node
struct node* newNode(int key)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return(node);
}

//to rotate right
struct node *rotright(struct node *y)
{
	struct node *x = y->left;
	struct node *T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;
	return x;
}
//to rotate left
struct node *rotLeft(struct node *key)
{
	struct node *m = key->right;
	struct node *t = m->left;
	m->left = key;
	key->right = t;
	key->height = max(height(key->left), height(key->right))+1;
	m->height = max(height(m->left), height(m->right))+1;
	return m;
}
//to find balance factor
int balfac(struct node *k)
{
	if (k == NULL)
    {
		return 0;
    }
	return height(k->left) - height(k->right);
}

struct node* Ins(struct node* node, int key)
{
	if (node == NULL)
    {
		return(newNode(key));
    }
	else if (key < node->key)
    {
		node->left = Ins(node->left, key);
    }
	else if (key > node->key)
    {
		node->right = Ins(node->right, key);
    }
	else
    { 
		return node;
    }
	node->height = 1 + max(height(node->left),height(node->right));
	int balance = balfac(node);
	if (balance > 1 && key < node->left->key)
    {
		return rotright(node);
    }
	else if (balance < -1 && key > node->right->key)
    {
		return rotLeft(node);
    }
	else if (balance > 1 && key > node->left->key)
	{
		node->left = rotLeft(node->left);
		return rotright(node);
	}
	else if (balance < -1 && key < node->right->key)
	{
		node->right = rotright(node->right);
		return rotLeft(node);
	}
	return node;
}

struct node * Nodemin(struct node* node)
{
	struct node* current = node;
	while (current->left != NULL)
    {
		current = current->left;
    }
	return current;
}

//to delete 
struct node* Del(struct node* rt, int key)
{
	if (rt == NULL)
    {
		return rt;
    }
	else if ( key < rt->key )
    {
		rt->left = Del(rt->left, key);
    }
	else if( key > rt->key )
    {
		rt->right = Del(rt->right, key);
    }
	else
	{
		if( (rt->left == NULL) || (rt->right == NULL) )
		{
			struct node *temp = rt->left ? rt->left :rt->right;
			if (temp == NULL)
			{
				temp = rt;
				rt = NULL;
			}
			else
			*rt = *temp;
			free(temp);
		}
		else
		{
			struct node* temp = Nodemin(rt->right);
			rt->key = temp->key;
			rt->right = Del(rt->right, temp->key);
		}
	}
	if (rt == NULL)
    {
	    return rt;
    }
	rt->height = 1 + max(height(rt->left),height(rt->right));
	int bal = balfac(rt);
	if (bal > 1 && balfac(rt->left) >= 0)
		return rotright(rt);

	if (bal > 1 && balfac(rt->left) < 0)
	{
		rt->left = rotLeft(rt->left);

		return rotright(rt);
	}

	if (bal < -1 && balfac(rt->right) <= 0)
		return rotLeft(rt);

	if (bal < -1 && balfac(rt->right) > 0)
	{
		rt->right = rotright(rt->right);

		return rotLeft(rt);
	}
	return rt;
}
//to show preorder traversal
void display(struct node *rt) 
{
    if (rt != NULL) 
    {
        printf("%d ", rt->key);
        display(rt->left);
        display(rt->right);
    }
}

//main function
int main()
{
    struct node *rt = NULL;
    while (1)
    {
        printf("\n----Operations----");
        printf("\nPress\t 1.insert\t 2.Delete\t 3.exit");
        printf("\nEnter your choice:");
        int choice,val,data;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : 
                printf("\nEnter integer to insert:");
                scanf("%d",&val);
                rt=Ins(rt,val);
                display(rt);
                break;
            case 2 : 
                printf("\nEnter integer to delete:");
                scanf("%d",&data);
                rt = Del(rt, data);
                printf("\n%d Deleted.",data);
                display(rt);
                break;
            case 3 : 
                printf("Exiting");
                exit(0);
            default : 
                printf("Invalid choice!!\n");
        }
    }   
	return 0;
}