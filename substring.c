//Program to count the occurrence of substring in a given
#include <stdio.h>
#include <string.h>
int countOccurrences(char * , char * );
int main()
{
    char str[100];
    char sub[100];
    int listcount;
    printf("\nEnter any string: ");
    gets(str);
    printf("\nEnter the substring to search : ");
    gets(sub);
    listcount = countOccurrences(str, sub);
    printf("Total occurrences of '%s': %d", sub, listcount);
    return 0;
}
int countOccurrences(char * str, char * sub)
{
    int i, j, found, listcount;
    int l1, l2;
    l1 = strlen(str);
    l2 = strlen(sub);
    listcount = 0;
    for(i=0; i <= l1-l2; i++)
    {
        found = 1;
        for(j=0; j<l2; j++)
        {
            if(str[i + j] != sub[j])
            {
                found = 0;
                break;
            }
        }
        if(found == 1)
        {
            listcount++;
        }
    }
    return listcount;
}