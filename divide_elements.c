#include "monty.h"
/**
 * divide_elements - divides second top element by top element of stack
 * @stack: stack starting from the top
 * @line_num: line number for current argument
 * Return: nothing
 */

void divide_elements(stack_t **stack, unsigned int line_num)
{
	int sum;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->next->n / (*stack)->n;

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);

	(*stack)->n = sum;
}
