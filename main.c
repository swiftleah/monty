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
	char opcode[100], argument_str[20];
	int argument;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
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
		if (sscanf(line, "%99s", opcode) == 1)
		{
			if (strcmp(opcode, "push") == 0)
			{
				if (sscanf(line, "push %19s", argument_str) == 1)
				{
					argument = atoi(argument_str);
					push_node(&stack, argument);
				}
				else
					exit(EXIT_FAILURE);
			}
			else if (strcmp(opcode, "pall$") == 0)
				pall_node(&stack);
			else
			{
				fprintf(stdout, "L%d: unknown instruction %s\n", line_num, opcode);
				exit(EXIT_FAILURE);
			}
		}
	}
	fclose(file);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
