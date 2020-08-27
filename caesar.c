/* caesar.c */

#include <stdio.h>

void shift(FILE *input, FILE *output, int key)
{
	char c;
	while((c = fgetc(input)) != EOF)
	{
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) // If alphabetic
		{
			if((c >= 'A') && (c <= 'Z')) // If uppercase
			{
				c = (c + key + 'A') % 26 + 'A';
			}
			else
			{
				c = (c + key + 'a') % 26 + 'a';
			}
		}
		fprintf(output, "%c", c);
	}
}
