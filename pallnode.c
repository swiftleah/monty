#include "monty.h"

/**
 * pall_node - prints the values on the stack, starting from the top
 * @stack: pointer to pointer to the stack, starting from the top
 * Return: nothing
 */

void pall_node(stack_t **stack)
{
	stack_t *current = *stack;

	if (*stack == NULL)
		exit(EXIT_FAILURE);

	while (current != NULL)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
	free(current);
}
