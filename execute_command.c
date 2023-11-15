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
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};

	opc = strtok(line, " \n\t");
	if (opc == NULL || opc[0] == '#' || strcmp(opc, "nop") == 0)
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
