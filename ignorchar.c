//Program to count the number of occurences of each character ignoring the case of alphabets
#include <stdio.h>
#include <string.h>
 
int main()
{
   char string[100];
   int c = 0, listcount = 0, x;
 
   printf("Enter a string\n");
   gets(string);
 
   while (string[c] != '\0') 
   {
 
      if (string[c] >= 'a' && string[c] <= 'z'|| string[c]) 
      {
         x = string[c] - 'a';
         listcount[x]++;
      }
 
      c++;
   }
 
   for (c = 0; c < 26; c++)
         printf("%c occurs %d times in the string.\n", c + 'a', listcount[c]);
 
   return 0;
}