#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/kernel.h>

/* Structs: */

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

/* Prototypes: */
void push_node(stack_t **stack, int n);
void pall_node(stack_t **stack);
int main(int argc, char *argv[]);
void free_stack(stack_t *stack);
void pint_node(stack_t *stack, unsigned int line_num);
void pop_node(stack_t **stack, unsigned int line_num);
void swap_element(stack_t **stack, unsigned int line_num);

/* Mathematical Functions: */
void add_element(stack_t **stack, unsigned int line_num);
void divide_elements(stack_t **stack, unsigned int line_num);
void subtract_elements(stack_t **stack, unsigned int line_num);
void multiply_elements(stack_t **stack, unsigned int line_num);
void mod_elements(stack_t **stack, unsigned int line_num);
void pchar_element(stack_t *stack, unsigned int line_num);

/* Error Functions to make main shorter: */
void usagemonty_error(void);

#endif
