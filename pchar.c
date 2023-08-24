#include "monty.h"
/**
 * pchar_element - prints char of element of node
 * @stack: stack starting at top
 * @line_num: line number of current argument
 * Return: nothing
 */

void pchar_element(stack_t *stack, unsigned int line_num)
{
	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}

	if (stack->n < 0 || stack->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%c\n", stack->n);
}
