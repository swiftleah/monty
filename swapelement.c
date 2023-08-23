#include "monty.h"
/**
 * swap_element - swaps top two elements of stack
 * @stack: stack starting from the top
 * @line_num: line number of current argument
 * Return: nothing
 */

void swap_element(stack_t **stack, unsigned int line_num)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
