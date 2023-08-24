#include "monty.h"
/**
 * pushint_error - prints push int error message & exit failure
 * @line_num: line number of current argument
 * Return: nothing
 */

void pushint_error(unsigned int line_num)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_num);
	exit(EXIT_FAILURE);
}
