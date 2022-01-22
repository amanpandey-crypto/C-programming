//Program to add or remove student from a class

#include<stdio.h>
#include<stdlib.h>

// removal or branch changing of student
int RemoveStudent(int rank[100],int n)
{
	int j,m;
	printf("Enter rank of student to do branch transfer :\n");
	scanf("%d",&m);
	if(m>n||m<=0)   // checking of value of m to be valid or not
	{
		printf("Invalid rank of student.\n");
		exit(0) ;
	}
	for(j=m-1;j<n;j++)  
	{
		rank[j]=rank[j+1] ;
	}
	printf("After changing branch, Rank should be :\n");
	for(j=0;j<n-1;j++)
	{
 		printf("Rank %d: %d\n",j+1,rank[j]) ;
	}
	n-- ;
	return n ;
}

// Insertion of Roll no. in (k-1)th index

int InsertStudent(int rank[100],int n)
{
    int i,roll,k ;
	printf("Enter the roll no. to be added :");
	scanf("%d",&roll);
	for(i=0;i<n;i++)
	{
		if(rank[i]==roll)
		{
			printf("This roll no is already there.\n");
			exit(0);
		}
	}

	printf("Enter the Rank where to be added :");
	scanf("%d",&k);
	if(k>n+1||k<=0)   //checking value of the rank to be satisfying given condition or not
	{
		printf("Invalid rank.");
		exit(0);
	}
	for(i=n-1;i>k-2;i--)   //moving roll no one position forward
	{
		rank[i+1]=rank[i];
	}
	rank[k-1]=roll ;  
	printf("After adding new student, Rank should be :\n"); 
	for(i=0;i<n;i++)        
	{
 		printf("Rank %d: %d\n",i+1,rank[i]) ;
	}
	n++ ;
	return n;

}

// main program 

int main()
{
  	int N,n,i,j,rank[100],choice ;
	printf("Enter the class capacity:");
 	scanf("%d",&N);
	if(N<=5)    //checking for validity of N
	{
        printf("Class capacity should be greater than 5.");
	 	exit(0);
	} 
	printf("Enter no of students in class greater than 5:");
	scanf("%d",&n);
	if(n>N||n<=5)  //checking for validity of n
	{
		printf("Wrong entry.\n");
		exit(0);
	}
	printf("Enter roll no. according to the ascending order of the rank :");
	for(i=0;i<n;i++)
	{	
		scanf("%d",&rank[i]);
	}
	for(i=0;i<n;i++)         // Checking of already entered roll number
	{ 
		for(j=i+1;j<n;j++)
		{ 
			if(rank[i]==rank[j])
			{
				printf("Entered roll no. is already present.\n");	
				exit(0);
			}
		}
	}
	printf(" Presently Ranks of students are:\n");
	for(i=0;i<n;i++)
	{
 		printf("Rank %d:%d\n",i+1,rank[i]) ;
	}	
	while(1)
	{
		printf("Press:1 to remove student\nPress:2 to add student\nPress:3 to Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 :
                    if(n<=6)
                    {	
                        printf("Required number of student in class is 6.\n");
                        exit(0);
                    }
                    else
                        {	
                            RemoveStudent(rank,n);
                        }
                    break;
            case 2 :
                    if(n==N)
                    {
                        printf("Can not add student, class capacity is full.\n");
                        exit(0);
                    }
                    else
                    {
                        InsertStudent(rank,n);
                    }
                    break;
			case 3 : exit(0);
			default : printf("Invalid choice.");
		}
	}
    return 0;
}