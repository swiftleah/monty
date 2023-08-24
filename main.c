#include "monty.h"
/**
 * main - main function
 * @argc: argument count
 * @argv: argument vector
 * Return: exit success
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	unsigned int line_num = 0;
	FILE *file;
	char line[256], opcode[100], *token;

	if (argc != 2)
		usagemonty_error();
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file))
	{
		line_num++;
		token = strtok(line, " \t\n$");

		if (token == NULL || token[0] == '#')
			continue;
		if (sscanf(line, "%99s", opcode) == 1)
		{
			if (strcmp(opcode, "push") == 0)
			{
				token = strtok(NULL, " \t\n$");
				if (token)
				{
					int argument = atoi(token);
					push_node(&stack, argument);
				}
				else
					pushint_error(line_num);
			}
			else if (strcmp(opcode, "pall") == 0)
				pall_node(&stack);
			else if (strcmp(opcode, "pint") == 0)
				pint_node(stack, line_num);
			else if (strcmp(opcode, "pop") == 0)
				pop_node(&stack, line_num);
			else if (strcmp(opcode, "swap") == 0)
				swap_element(&stack, line_num);
			else if (strcmp(opcode, "add") == 0)
				add_element(&stack, line_num);
			else if (strcmp(opcode, "nop") == 0)
				continue;
			else if (strcmp(opcode, "div") == 0)
				divide_elements(&stack, line_num);
			else if (strcmp(opcode, "sub") == 0)
				subtract_elements(&stack, line_num);
			else if (strcmp(opcode, "mul") == 0)
				multiply_elements(&stack, line_num);
			else if (strcmp(opcode, "mod") == 0)
				mod_elements(&stack, line_num);
			else if (strcmp(opcode, "pchar") == 0)
				pchar_element(stack, line_num);
			else if (strcmp(opcode, "pstr") == 0)
				print_string(stack);
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
				exit(EXIT_FAILURE);
			}
		}
	}
	fclose(file);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
