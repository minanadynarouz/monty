#include "monty.h"

/**
 * add - add top 2 element together
 * @dll: doubly linked list
 * @line_num: line number
 */

void add(stack_t **dll, unsigned int line_num)
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
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	tmp = (*dll)->next;
	tmp->n = tmp->n + (*dll)->n;
	pop(dll, line_num);
}

/**
 * swap - swap top 2 element
 * @dll: doubly linked list
 * @line_num: line number
 */

void swap(stack_t **dll, unsigned int line_num)
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
                fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
                exit(EXIT_FAILURE);
        }
	tmp = *dll;
	*dll = (*dll)->next;
	tmp->next = (*dll)->next;
	tmp->prev = *dll;
	(*dll)->next = tmp;
	(*dll)->prev = NULL;
}

/**
 * sub - subtract top 2 element
 * @dll: doubly linked list
 * @line_num: line number
 */

void sub(stack_t **dll, unsigned int line_num)
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
                fprintf(stderr, "L%u: can't sub, stack too short\n", line_num);
                exit(EXIT_FAILURE);
        }
        tmp = (*dll)->next;
        tmp->n = tmp->n - (*dll)->n;
        pop(dll, line_num);
}

/**
 * divide - divide top 2 element
 * @dll: doubly linked list
 * @line_num: line number
 */

void divide(stack_t **dll, unsigned int line_num)
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
                fprintf(stderr, "L%u: can't div, stack too short\n", line_num);
                exit(EXIT_FAILURE);
        }

	if ((*dll)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}

        tmp = (*dll)->next;
        tmp->n = tmp->n / (*dll)->n;
        pop(dll, line_num);
}

/**
 * mult - mult top 2 element together
 * @dll: doubly linked list
 * @line_num: line number
 */

void mult(stack_t **dll, unsigned int line_num)
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
                fprintf(stderr, "L%u: can't mul, stack too short\n", line_num);
                exit(EXIT_FAILURE);
        }
        tmp = (*dll)->next;
        tmp->n = tmp->n * (*dll)->n;
        pop(dll, line_num);
}
