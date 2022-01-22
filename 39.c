#include<stdio.h>
#include<string.h>
struct student
{
    char name[100],branch[30],roll_num[100];
    int year,sem;
};
int main()
{
    int n;
    printf("Enter the no. of students :");
    scanf("%d",&n);
    getchar();
    struct student e[n];
    int i;
    for(i=0;i<n;++i)
    {
        printf("Enter  student's name :");
        gets(e[i].name);
        printf("\nEnter roll number :");
        gets(e[i].roll_num);
        printf("\nEnter name of branch :");
        gets(e[i].branch);
        printf("\nEnter year :");
        scanf("%d",&e[i].year);
        printf("\nEnter semester :");
        scanf("%d",&e[i].sem);
        getchar();
    }
    printf("\n The details are : ");
    for(i=0;i<n;++i)
    {
        printf("\nName - %s",e[i].name);
        printf("\nRoll number - %s",e[i].roll_num);
        printf("\nBranch - %s",e[i].branch);
        printf("\nYear - %d",e[i].year);
        printf("\nSemester - %d",e[i].sem);  
    }
    return 0;
}
