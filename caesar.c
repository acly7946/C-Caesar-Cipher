/* caesar.c */

#include <stdio.h>
#include <ctype.h>

void shift(FILE *input, FILE *output, int key)
{
	char c;
	while((c = fgetc(input)) != EOF)
	{
		if (isalpha(c))
		{
			if(isupper(c))
			{
				c = (c + key - 'A') % 26 + 'A';
			}
			else
			{
				c = (c + key - 'a') % 26 + 'a';
			}
		}
		fprintf(output, "%c", c);
	}
}
