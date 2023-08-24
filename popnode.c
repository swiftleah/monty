#include "monty.h"
/**
 * pop_node - removes the top element of the stack
 * @stack: stack starting from the top
 * @line_num: line number of current argument
 * Return: nothing
 */

void pop_node(stack_t **stack, unsigned int line_num)
{
	stack_t *top;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	*stack = top->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

}
