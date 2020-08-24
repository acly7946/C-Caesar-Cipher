/* main.c */

#include "ceasar.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>
#include <string.h>
#include <errno.h>
#include <getopt.h>

#define OPTSTR "hi:o:s:"
#define ERROR_INPUT_ARG "--input"
#define ERROR_OUTPUT_ARG "--output"
#define ERROR_SHIFT_ARG "--shift"

extern int errno;
extern char *optarg;
extern int opterr, optind;

typedef struct
{
	FILE *input;
	FILE *output;
	int shift;
}	options_t;

void usage(FILE *stream, char *programName);

int main(int argc, char *argv[])
{
	int opt;
    options_t options = {stdin, stdout, 13};
	static struct option long_options[] =
	{
		{"help", no_argument, NULL, 'h'},
		{"input", required_argument, NULL, 'i'},
		{"output", required_argument, NULL, 'o'},
		{"shift", required_argument, NULL, 'h'},
	};

    while ((opt = getopt_long(argc, argv, OPTSTR, long_options, NULL)) != EOF)
	{
		switch(opt)
		{
			case 'h':
				usage(stdout, basename(argv[0]));
				break;

			case 'i':
				if(!(options.input = fopen(optarg, "r")))
				{
					perror(ERROR_INPUT_ARG);
					exit(EXIT_FAILURE);
				}
				break;

			case 'o':
				if(!(options.output = fopen(optarg, "w")))
				{
					perror(ERROR_OUTPUT_ARG);
					exit(EXIT_FAILURE);
				}
				break;

			case 's':
				if(!(sscanf(optarg, "%d", &options.shift)))
				{
					errno = 22;
					perror(ERROR_SHIFT_ARG);
					exit(EXIT_FAILURE);
				}
				break;

			default:// ? and :
				usage(stderr, basename(argv[0]));
				break;
		}
	}

	// ceasar/unceasar
	if(strcmp(basename(argv[0]), "ceasar") == 0)
	{
		shift(options.input, options.output, options.shift);
	}
	else
	{
		shift(options.input, options.output, -options.shift);
	}

	return EXIT_SUCCESS;
}

void usage(FILE *stream, char *programName)
{
	char *usageFormat =
	"  -h, --help      Show help message and exit\n"
	"  -i, --input     File to use as input (default: stdin)\n"
	"  -o, --output    File to use as output (default: stdout)\n"
	"  -s, --shift     Amount of characters to shift by (default: 13)\n";

	char *usage = malloc(strlen("Usage: ") + strlen(programName) + strlen(" [OPTIONS]\n\n") + strlen(usageFormat) + 1);
	sprintf(usage, "Usage: %s [OPTIONS]\n\n%s", programName, usageFormat);
	fprintf(stream, "%s", usage);
	free(usage);
	exit(EXIT_SUCCESS);
}
