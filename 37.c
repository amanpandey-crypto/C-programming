/*

	Word Search (Pointers)

		Write a C Program to search for a word in a given array of strings using pointers

*/

#include <stdio.h>
#include <string.h>
int main ()
{
	char str[100][100], word[100];
	int size;
    printf("\n Enter the size :");
	scanf ("%d", &size);

	getchar ();

	for (int i = 0; i < size; i++)

		scanf ("%s", str[i]);

	scanf ("%s", word);



	char (*ptr)[100] = str;

	for (int i = 0; i < size; ++i)

	{

		if (strcasecmp (word, *(ptr + i)) == 0)

			printf ("\tMatched with string[%d] : %s\n", i, *(ptr + i));

	}



	return 0;

}