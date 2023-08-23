#include "monty.h"
/**
 * free_stack - frees memory allocated during program execution
 * @stack: struct
 * Return: nothing
 */

void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
