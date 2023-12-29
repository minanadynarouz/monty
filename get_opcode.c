#include "monty.h"

/**
 * get_opcode - select the correct opcode to execute
 * @opc: opcode
 * Return: pointer to the function that executes the opcode
 */

void (*get_opcode(char *opc))(stack_t **stack, unsigned int line_number)
{
	int i;

	instruction_t instruction[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{"add", add},
		{"swap", swap},
		{"sub", sub},
		{"div", divide},
		{"mul", mult},
		{"mod", modu},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}};

	for (i = 0; instruction[i].opcode; i++)
	{
		if (strcmp(instruction[i].opcode, opc) == 0)
			break;
	}
	return (instruction[i].f);
}
