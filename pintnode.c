#include "monty.h"
/**
 * print_node - prints value at top of the stack
 * @stack: stack starting from the top
 * @line_num: line number of current argument
 * Return: nothing
 */
void pint_node(stack_t *stack, unsigned int line_num)
{
	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", stack->n);
}
