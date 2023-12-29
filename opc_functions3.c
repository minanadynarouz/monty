#include "monty.h"
/**
 * rot1 - rotate the stack to the top
 * @dll: doubly linked list
 * @line_num: line number
 */

void rot1(stack_t **dll, unsigned int line_num)
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
