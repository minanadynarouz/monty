#include "monty.h"

/**
 * input_file_validation - validate user inserted a correct file
 * @argc: count to check input
 * @argv: file to open
 */

FILE *input_file_validation(int argCount, char *file_index_1)
{
	FILE *fp;
	if (argCount != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);

	fp = fopen(file_index_1, "r");
	if (!fp)
		fprintf(stderr, "Error: Can't open file %s\n", file_index_1), exit(EXIT_FAILURE);
	return (fp);
}

