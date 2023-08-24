#include "monty.h"
/**
 * rotl_node - top element becomes last one, second top element becomes
 * first one
 * @stack: stack starting from the top
 * Return: nothing
 */

void rotl_node(stack_t **stack)
{
	stack_t *last;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		last = *stack;

		while (last->next != NULL)
			last = last->next;

		last->next = *stack;
		(*stack)->prev = last;

		*stack = (*stack)->next;
		(*stack)->prev = NULL;

		last->next->next = NULL;
	}
}
