#include "monty.h"
/**
 * add_element - adds two top elements of the stack
 * @stack: stack starting from the top
 * @line_num: line number of current argument
 * Return: nothing
 */

void add_element(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;
	int sum = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);

	(*stack)->n = sum;
}
