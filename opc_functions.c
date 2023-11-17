#include "monty.h"

/**
 * push - pushe element to the stack
 * @dll: doubly linked list
 * @line_num: line number
 */

void push(stack_t **dll, unsigned int line_num)
{
	int i, num;

	if (!globVars.arg)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}

	for (i = 0; globVars.arg[i]; i++)
	{
		if (!isdigit(globVars.arg[i]) && globVars.arg[i] != '-')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
	}

	num = atoi(globVars.arg);

	if (globVars.format == 1)
		add_dll_begining(dll, num);
	else
		add_dll_end(dll, num);
}

/**
 * pall - print all values of the stack
 * @dll: doubly linked list
 * @line_num: line numbers
 */

void pall(stack_t **dll, unsigned int line_num)
{
	stack_t *tmp;
	(void)line_num;

	tmp = *dll;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * nop - do nothing
 * @dll: doubly linked list
 * @line_num: line numbers
 */

void nop(stack_t **dll, unsigned int line_num)
{
	(void)dll;
	(void)line_num;
}

/**
 * pint - print value at top of the stack
 * @dll: doubly linked list
 * @line_num: line numbers
 */

void pint(stack_t **dll, unsigned int line_num)
{
        if (*dll == NULL)
        {
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
                exit(EXIT_FAILURE);
        }
	printf("%d\n", (*dll)->n);
}

/**
 * pop - remove value at top of the stack
 * @dll: doubly linked list
 * @line_num: line numbers
 */

void pop(stack_t **dll, unsigned int line_num)
{
	stack_t *tmp;

	if (dll == NULL || *dll == NULL)
	{
                fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
                exit(EXIT_FAILURE);
	}

	tmp = *dll;
	*dll = (*dll)->next;
	free(tmp);
}
