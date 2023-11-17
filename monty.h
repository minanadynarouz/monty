#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{

	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct globals - global structure to use in the functions
 * @arg: second parameter inside the current line
 * @head: doubly linked list
 * @format: to define if stack or queue
 * @line_number: hold line number to show error at which line
 * @buffer: input text
 */
typedef struct globals
{
	int format;
	unsigned int line_number;
	char *arg;
	stack_t *head;
	char *buffer;
} global_t;

extern global_t globVars;

/*-----Function Prototypes-----*/
void (*get_opcode(char *opc))(stack_t **stack, unsigned int line_number);
void free_dll(stack_t *head);
stack_t *add_dll_end(stack_t **head, const int n);
stack_t *add_dll_begining(stack_t **head, const int n);

/*-----Helper Functions-----*/
FILE *input_file_validation(int argCount, char *file_index_1);
void free_globals(void);
void define_globals(void);

/*-----OPCODE FUNCTIONS-----*/
void push(stack_t **dll, unsigned int line_num);
void pall(stack_t **dll, unsigned int line_num);
void nop(stack_t **dll, unsigned int line_num);
void pint(stack_t **dll, unsigned int line_num);

#endif
