#include "monty.h"
/**
 * rotr_node - last element becomes top element
 * @stack: stack starting from the top
 * Return: nothing
 */

void rotr_node(stack_t **stack)
{
	stack_t *current;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		current = *stack;

		while (current->next != NULL)
			current = current->next;

		current->prev->next = NULL;
		current->next = *stack;
		(*stack)->prev = current;
		current->prev = NULL;

		*stack = current;
	}
}
