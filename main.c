#include "monty.h"
/**
 * main - main function
 * @argc: argument count
 * @argv: argument vector
 * Return:
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	char line[256];
	unsigned int line_num = 0;
	FILE *file;
	char opcode[64];
	int argument;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file))
	{
		line_num++;
		if (sscanf(line, "%63s %d", opcode, &argument) == 2)
		{
			if (strcmp(opcode, "push") == 0)
				push_node(&stack, argument);
			else if (strcmp(opcode, "pall") == 0)
				pall_node(&stack);
		}
	}
	fclose(file);
	return (EXIT_SUCCESS);
}
