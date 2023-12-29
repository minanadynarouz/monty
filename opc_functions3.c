#include "monty.h"
/**
 * rotl - rotate the stack to the top
 * @dll: doubly linked list
 * @line_num: line number
 */

void rotl(stack_t **dll, unsigned int __attribute__((__unused__)) line_num)
{
	stack_t *temp, *tempLast;

	if (*dll == NULL || (*dll)->next == NULL)
		return;

	temp = *dll;
	tempLast = *dll;
	*dll = (*dll)->next;
	(*dll)->prev = NULL;

	while(temp != NULL)
	{
		temp = temp->next;
	}
	temp->next = tempLast;
	tempLast->next = NULL;
	tempLast->prev = temp;
}
