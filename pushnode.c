#include "monty.h"

/**
 * push_node - creates new node and pushes it on stack
 * @stack: pointer to pointer to stack from the top
 * @n: int value of new node
 * Return: nothing
 */

void push_node(stack_t **stack, int n)
{
	stack_t *newNode = (stack_t *)malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = n;
	newNode->prev = NULL;

	if (*stack != NULL)
	{
		newNode->next = *stack;
		(*stack)->prev = newNode;
	}
	else
		newNode->next = NULL;

	*stack = newNode;
}
