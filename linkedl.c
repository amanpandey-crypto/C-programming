#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data; // member variable
	struct node *next;
} *start=NULL, *current, *newNode ; // global object

void InsertB(int value)
{
// create a node using DMA, malloc()

	newNode=(struct node *) malloc(sizeof(struct node));
	newNode->data= value;
	newNode->next= NULL;
	
	if(start== NULL)
	{
		start = newNode;
	}
	else
	{
		newNode->next= start;
		start=newNode;
	}

}

void InsertM(int key, int value)
{
	// creae a node	
	newNode=(struct node *) malloc(sizeof(struct node));
	newNode->data= value;
	newNode->next= NULL;
	
	current=start; // cauion, copy address of start to current pointer
	while(current->data != key ) // stoping condiion
	{
		current= current->next; 
	}
	newNode->next= current->next;
	current->next = newNode;

}

void InsertE(int value)
{
	// creae a node	
	newNode=(struct node *) malloc(sizeof(struct node));
	newNode->data= value;
	newNode->next= NULL;
	
	current=start; // cauion, copy address of start to current pointer
	
	while(current->next != NULL ) // stoping condiion
	{
		current= current->next; 
	}

	current->next = newNode;

}

void DeleteB()
{
	current = start; // assign address of start to current pointer
	
	if(current->next == NULL) // list contains exactly one item
	{
		start= NULL;
		free(current);
	}
	
	else
	{
		start=current->next;
		free(current);
	}
	
}

void DeleteM(int key)
{
	struct node *prev;
	current= start;
	
	while(current->data != key)
	{
		prev = current; // copy the address of current to prev pointer
		current=current->next;
	}
	
	prev->next=current->next;
	free(current);
	
}

void DeleteE()
{
	struct node * prev;
	current=start;
	
	while(current->next != NULL)
	{
		prev = current; 
		current= current->next;
	}
	
	prev->next= NULL;
	free(current);
	
}

void display()
{
	current = start; // copy address of start to current
	
	if(current == NULL)
	{
		printf("The list is empty \n");
	}
	
	else
	{
		while(current != NULL)
		{
			printf("%d->", current->data);
			current=current->next;
		}
	
		printf("NULL \n");
	}
	
	
	
		
}
void main()
{
	int choice, value, key;
	while(1)
	{
		printf("Enter your choice: \t 1. InsertB \t2. InsertM \t 3. InsertE \t 4. DeleteB \t 5. DeleteM \t 6. DeleteE \t 7. Exit \n");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter the value to insert in the begining\n");
				scanf("%d", &value);
				InsertB(value); // calling funcion
				display();
				break;
				case 2:
					printf("Enter the value to insert in the middle:\n");
					scanf("%d", &value);
					printf("After which element do you want to insert? \n");
					scanf("%d", &key);
					InsertM(key,value); // calling funcion
					display();
					break;
					case 3:
						printf("Enter the value to insert in the end \n");
						scanf("%d", &value);
						InsertE(value); // calling funcion
						display();
						break;
						case 4:
							DeleteB();
							display();
							break;
							case 5: 
								printf("which node element do you want to delete?\n");
								scanf("%d",&key);
								DeleteM(key);
								display();
								break;
								case 6: 
									DeleteE();
									display();
									break;
								case 7:
									exit(0);
		}
		
	}
	
}

