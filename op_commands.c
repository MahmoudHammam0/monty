#include "monty.h"

/**
 * _push - push an int to the stack
 *
 * @stack: the stack
 * @line_number: the number of the line in the file
 */
void _push(stack_t **stack, unsigned int line_number)
{
	int num;
	stack_t *ptr;
	stack_t *temp = *stack;

	num = read_line(line_number);
	ptr = malloc(sizeof(stack_t));
	if (ptr == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	ptr->n = num;
	ptr->prev = NULL;
	if (temp == NULL)
	{
		ptr->next = NULL;
		*stack = ptr;
	}
	else
	{
		ptr->next = temp;
		temp->prev = ptr;
		*stack = ptr;
	}
}

/**
 * _pall - prints all the elements of the stack
 *
 * @stack: the stack
 * @line_number: the number of the line in the file
 */
void _pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *ptr = *stack;

	if (ptr == NULL)
		return;
	else
	{
		while (ptr != NULL)
		{
			dprintf(1, "%d\n", ptr->n);
			ptr = ptr->next;
		}
	}
}
