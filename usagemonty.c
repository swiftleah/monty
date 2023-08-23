#include "monty.h"
/**
 * usagemonty - prints error message and exits
 * Return: exit failure
 */
void usagemonty_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
