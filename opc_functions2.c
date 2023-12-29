#include "monty.h"
/**
 * modu - get modulos of top 2 element
 * @dll: doubly linked list
 * @line_num: line number
 */

void modu(stack_t **dll, unsigned int line_num)
{
	int i;
	stack_t *tmp;

	tmp = *dll;

	i = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}

	if (i < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	if ((*dll)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}

	tmp = (*dll)->next;
	tmp->n = tmp->n % (*dll)->n;
	pop(dll, line_num);
}

void queue(stack_t **dll, unsigned int line_num)
{
    (void)dll;
    (void)line_num;

    globVars.format = 0;
}

/**
 * stack - set the format fo the data to stack
 * @dll: head of the linked list
 * @line_num: line number;
 */
void _stack(stack_t **dll, unsigned int line_num)
{
    (void)dll;
    (void)line_num;

    globVars.format = 1;
}

/**
 * pchar - print char at top of the stack
 * @dll: doubly linked list
 * @line_num: line numbers
 */

void pchar(stack_t **dll, unsigned int line_num)
{
	int value;

	if (*dll == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	value = (*dll)->n;
	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", value);
}


/**
 * pstr - print string at top of the stack
 * @dll: doubly linked list
 * @line_num: line number;
 */
void pstr(stack_t **dll, unsigned int line_num)
{
	int value;

	while (*dll != NULL)
	{
		value = (*dll)->n;
		if ((value >= 65 && value <= 90) || (value >= 97 && value <= 122))
		{
			printf("%c", value);
		}
		*dll = (*dll)->next;
	}
	printf("\n");
}
