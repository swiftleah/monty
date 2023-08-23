#include "monty.h"
/**
 * subtract_elements - subtracts top element from second top element of stack
 * @stack: struct
 * @line_num: line number for current argument
 * Return: nothing
 */

void subtract_elements(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;
	int sum = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short", line_num);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->next->n - (*stack)->n;

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);

	(*stack)->n = sum;
}
