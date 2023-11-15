#include "monty.h"

/**
 * _pchar - prints the char at the top of the stack, followed by a new line
 *
 * @stack: pointer to top of the stack
 * @line_number: number of the line to be executed
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || (*stack) == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	dprintf(1, "%c\n", (*stack)->n);
}

/**
 * _pstr - prints the string starting at the top of the stack, followed
 * by a new line
 *
 * @stack: pointer to top of the stack
 * @line_number: number of the line to be executed
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	(void)line_number;

	if (ptr == NULL)
	{
		dprintf(1, "\n");
		return;
	}

	while (ptr && ptr->n != 0 && (ptr->n > 0 && ptr->n <= 127))
	{
		dprintf(1, "%c", (char)ptr->n);
		ptr = ptr->next;
	}

	dprintf(1, "\n");
}
