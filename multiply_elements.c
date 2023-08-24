#include "monty.h"
/**
 * multiply_elements - multiplies second top element with top element of stack
 * @stack: stack starting from the top
 * @line_num: line number of current argument
 * Return: nothing
 */

void multiply_element(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;
	int sum = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->next->n * (*stack)->n;

	temp = *stack;
	*stack = (*stack)->next;
	(*stck)->prev = NULL;
	free(temp);

	(*stack)->n = sum;
}
