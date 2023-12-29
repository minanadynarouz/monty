#include "monty.h"
/**
 * rotl - rotate the stack to the top
 * @dll: doubly linked list
 * @line_num: line number
 */

void rotl(stack_t **dll, unsigned int __attribute__((__unused__)) line_num)
{
	stack_t *temp;

	temp = *dll;
	*dll = (*dll)->next;
	(*dll)->prev = NULL;

	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *dll;
	temp->next->next = NULL;
	temp->next->prev = temp;
}
