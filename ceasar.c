/* ceasar.c */

#include <stdio.h>

void endecode(FILE *input, FILE *output)
{
	// TODO: make it actually do stuff
	char c;
	while((c = fgetc(input)) != EOF)
	{
		fprintf(output, "%c", c);
	}
}
