#include<stdio.h>
#include<stdlib.h>
struct student
{
    char *name;
    char *rollno;
    struct dob
    {
        int dd,mm,yyyy;
    }DOB;
    struct subject
    {
        float E,H,M,SC,SST;
    }SB;
};
void main()
{
    FILE *fptr;
    float tm,avg=0;
    int i,s,n,r,mark=0;
    fptr=fopen("Student.c","w");
    printf("How many records do you want to store:");
    scanf("%d",&s);
    struct student S[s];
    printf("\nMaximum number of characters in name:");
    scanf("%d",&n);
    S->name=(char*)malloc(n*sizeof(char));
    printf("\nLength of roll number will be:");
    scanf("%d",&r);
    S->rollno=(char*)malloc(r*sizeof(char));
    for(i=0;i<s;i++)
    {
        printf("\nEnter the name of student:");
        scanf("%s",S->name);
        printf("\nEnter the roll number:");
        scanf("%s",S->rollno);
        printf("\nEnter the DOB in dd/mm/yyyy format:");
        scanf("%d %d %d",&S->DOB.dd,&S->DOB.mm,&S->DOB.yyyy);
        printf("\nEnter the marks in English:");
        scanf("%f",&S->SB.E);
        printf("\nEnter the marks in Hindi:");
        scanf("%f",&S->SB.H);
        printf("\nEnter the marks in Mathematics:");
        scanf("%f",&S->SB.M);
        printf("\nEnter the marks in Science:");
        scanf("%f",&S->SB.SC);
        printf("\nEnter the marks in Social Science:");
        scanf("%f",&S->SB.SST);
        tm=(S->SB.E+S->SB.H+S->SB.M+S->SB.SC+S->SB.SST);
        fprintf(fptr,"%s %s %d %d %d %f %f %f %f %f %f ",S->name,S->rollno,S->DOB.dd,S->DOB.mm,S->DOB.yyyy,S->SB.E,S->SB.H,S->SB.M,S->SB.SC,S->SB.SST,tm);
    }
    fclose(fptr);
    fptr=fopen("Student.c","r");
    printf("\nNAME\tROLL NO.\tDOB\tENGLISH\tHINDI\tMATHEMATICS\tSCIENCE\tSOCIAL STUDIES\t\tTOTAL MARKS\n");
    for(i=0;i<s;i++)
    {
        fscanf(fptr,"%s %s %d %d %d %f %f %f %f %f %f",S->name,S->rollno,&S->DOB.dd,&S->DOB.mm,&S->DOB.yyyy,&S->SB.E,&S->SB.H,&S->SB.M,&S->SB.SC,&S->SB.SST,&tm);
        printf("%s\t %s\t %d\t %d\t %d\t %f\t %f\t %f\t %f\t %f \t%f  \n",S->name,S->rollno,S->DOB.dd,S->DOB.mm,S->DOB.yyyy,S->SB.E,S->SB.H,S->SB.M,S->SB.SC,S->SB.SST,tm);
        mark+=tm;
    }
    avg=(mark)/s;
    printf("The average marks of class is %f",avg);
    fclose(fptr);
}