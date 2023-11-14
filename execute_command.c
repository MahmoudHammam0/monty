#include "monty.h"

/**
 * execute_command - executes the appropriate opcode
 *
 * @line: the line from the monty file
 * @stack: the stack
 * @line_number: the number of the line passed from the file
 */
void execute_command(char *line, stack_t **stack, unsigned int line_number)
{
	char *opc;
	int i;
	instruction_t instruction[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};

	opc = strtok(line, " \t\n");
	if (opc == NULL || opc[0] == '#')
		return;
	for (i = 0; instruction[i].opcode != NULL; i++)
	{
		if (strcmp(instruction[i].opcode, opc) == 0)
		{
			instruction[i].f(stack, line_number);
			return;
		}
	}
	if (instruction[i].opcode == NULL)
	{
		dprintf(2, "L%u: unknown instruction %s\n", line_number, opc);
		exit(EXIT_FAILURE);
	}
}
