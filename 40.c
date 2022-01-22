#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct contact
{
    char name[20];
    long int phone_num;
};
int main()
{
    int size,i;
    printf("Enter the number of contact details : ");
    scanf("%d",&size);
    getchar();
    struct contact e[size];
    for(i=0;i<size;++i)
    {
        printf("\nEnter name of the person :");
        gets(e[i].name);
        printf("\nEnter phone number :");
        scanf("%ld",&e[i].phone_num);
        getchar();
    }
    char search[100];
    printf("\nEnter the name to find :");
    gets(search);
    int flag=0;
    for(i=0;i<size;++i)
    {
        if(strcmp(e[i].name,search)==0)
        {
            printf("\nPhone number : %ld",e[i].phone_num);
            flag++;
        }
    }
    if(flag==0)
    {
        printf("\nContact details is not there.");
        exit(1);
    }
    else if(flag>1)
    {
        printf("\nMultiple contact details are there.");
        exit(0);
    }
    return 0;
}
