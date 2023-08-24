#include "monty.h"
/**
 * mod_elements - computes the rest of the div of second top element by top
 * @stack: stack starting from the top
 * @line_num: line number of current argument
 * Return: nothing
 */

void mod_elements(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;
	int remainder = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}

	remainder = (*stack)->next->n % (*stack)->n;

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);

	(*stack)->n = remainder;
}
