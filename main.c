#include "monty.h"

global_t globVars;

/**
 * free_globals - frees the global variables
 */

void free_globals(void)
{
	free_dll(globVars.head);
	free(globVars.buffer);
}

/**
 * define_globals - initialize the global variables
 */

void define_globals()
{
	globVars.format = 1;
	globVars.buffer = NULL;
	globVars.arg = NULL;
	globVars.line_number = 1;
}

/**
 * main - Program Entry
 * @argc: Count of arguments
 * @argv: Argument vector
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	FILE *fp;
	size_t size = 256;
	ssize_t n_lines = 0;
	char *lines[2] = {NULL, NULL};
	void (*implement_opc)(stack_t **stack, unsigned int line_number);

	fp = input_file_validation(argc, argv[1]);
	define_globals();

	while ((n_lines = getline(&globVars.buffer, &size, fp)) != -1)
	{
		lines[0] = strtok(globVars.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			implement_opc = get_opcode(lines[0]);
			if (!implement_opc)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", globVars.line_number, lines[0]);
				free_globals();
				fclose(fp);
				exit(EXIT_FAILURE);
			}
			globVars.arg = strtok(NULL, " \t\n");
			implement_opc(&globVars.head, globVars.line_number);
		}
		globVars.line_number++;
	}
	free_globals();
	fclose(fp);
	return (0);
}
