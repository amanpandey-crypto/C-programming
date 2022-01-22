#include<stdio.h>
#include<string.h>
int main ()
{

  FILE *p ;
  int countline=0 ,i=0 ;
  p= fopen("b.txt","r") ;
  if(p==NULL )
  {
    printf("file is not present \n ") ;
  }
  else
  { 
    printf("file is present \n " ) ; 
  }
  char ch ;
  ch = fgetc(p) ;
  while (ch!=EOF )
  {
      if(ch=='\n')
      {
        printf("\n%d",countline); 
        countline++ ;
      }
      printf("\n%c",ch);
      ch=fgetc(p);
  }
  fclose(p);
  return 0 ;
}