#include "monty.h"
/**
 * print_string - prints string starting at the top of stack
 * @stack: stack starting at the top
 * Return: nothing
 */

void print_string(stack_t *stack)
{
	stack_t *current = stack;

	while (current != NULL && current->n != 0 && (current->n >= 0 && current->n <= 127))
	{
		fprintf(stdout, "%c", current->n);
		current = current->next;
	}
	fprintf(stdout, "\n");
}
