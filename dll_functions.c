#include "monty.h"

/**
 * add_dll_begining - func to add node to the begining of DLL.
 * @head: DLL
 * @n: value data of Node
 * Return: address of new element or null if failed
 */

stack_t *add_dll_begining(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_globals();
		return (NULL);
	}
	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	if (*head == NULL)
		*head = new;
	else
	{
		new->next = *head;
		(*head)->prev = new;
		*head = new;
	}
	return (new);
}

/**
 * add_dll_end - func to add node to the end of dll.
 * @head: DLL
 * @n: value data of Node
 * Return: address of new element or null if failed
 */

stack_t *add_dll_end(stack_t **head, const int n)
{
	stack_t *new;
	stack_t *runner = *head;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_globals();
		return (NULL);
	}
	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	if (*head == NULL)
		*head = new;
	else
	{
		while (runner->next != NULL)
		{
			runner = runner->next;
		}
		runner->next = new;
		new->prev = runner;
	}
	return (new);
}

/**
 * free_dll - func to free DLL.
 * @head: DLL
 */

void free_dll(stack_t *head)
{
	while (head != NULL)
	{
		free(head);
		head = head->next;
	}
	free(head);
}
