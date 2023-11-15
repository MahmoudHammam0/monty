#include "monty.h"

/**
 * _pchar - prints the char at the top of the stack, followed by a new line
 *
 * @stack: pointer to top of the stack
 * @line_number: number of the line to be executed
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int num = ptr->n;
	char c;

	if (ptr == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (num < 64 || num > 127)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	c = (char)num;
	dprintf(1, "%c\n", c);
}
