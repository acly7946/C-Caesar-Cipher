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
				c += key % 26;
				if(c >= 'Z') { c -= key % 26; }
			}
			else
			{
				c += key % 26;
				if(c >= 'z') { c -= key % 26; }
			}
		}
		fprintf(output, "%c", c);
	}
}
