#include "monty.h"
/**
 * pop_node - removes the top element of the stack
 * @stack: stack starting from the top
 * @line_num: line number of current argument
 * Return: nothing
 */

int pop_node(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;
	int value;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	/**top = *stack;
	*stack = top->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(top);*/
	value = (*stack)->n;
    temp = *stack;
    *stack = (*stack)->next;
    if (*stack)
        (*stack)->prev = NULL;
    free(temp);
    
    return value;
}
