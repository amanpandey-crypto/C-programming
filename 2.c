#include <stdio.h>
#include <stdlib.h>
 
int main()
{
   FILE *f1 ,*f2;
   char s[20];
   unsigned char b;
   printf("\nEnter file name :");
   gets(s);
   f1=fopen("s","rb");
   f2=fopen("e.txt","wb");
   b=7;
   while(b!=EOF)
   {
      fread(&b,1,1,f1);
      fwrite(&b,1,1,f2);
   }
   fclose(f1);
   fclose(f2);
   printf("\n DONE.");
   getch();
   return 0;
  
}