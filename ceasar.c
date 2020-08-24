/* ceasar.c */

#include <stdio.h>

void shift(FILE *input, FILE *output, int key)
{
	char c;
	while((c = fgetc(input)) != EOF)
	{
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) // If alphabetic
		{
			if((c >= 'A') & (c <= 'Z')) // If uppercase
			{
				c = (c + key - 65) % 26 + 65;
			}
			else
			{
				c = (c + key - 97) % 26 + 97;
			}
		}
		fprintf(output, "%c", c);
	}
}
