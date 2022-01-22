#include<stdio.h>
#include<string.h>
int main()
{
   char str[100],new_ch,*p,ch;
   printf("Enter the string : ");
   gets(str);
   printf("\nEnter the character to replace and place there : ");
   scanf("%c %c",&ch,&new_ch);
   p=str;
   while(*p!='\0')
   {
      if(*p==ch)
      {
         *p=new_ch;
      }
      *p++;
   }
   printf("\nThe string after change is :");
   puts(str);
   return 0;
}
