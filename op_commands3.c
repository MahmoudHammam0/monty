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

/**
 * _rotl - rotates the stack to the top.
 * @stack: pointer to top of the stack
 * @line_number: number of line to be executed
 * Return: Nothing
 */
void _rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *ptr1, *ptr2;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return;
	ptr1 = ptr2 = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	if ((*stack)->next == NULL)
	{
		(*stack)->next = ptr1;
		ptr1->next = NULL;
		ptr1->prev = (*stack);
		return;
	}
	while (ptr2->next != NULL)
		ptr2 = ptr2->next;
	ptr2->next = ptr1;
	ptr1->prev = ptr2;
	ptr1->next = NULL;
}

/**
 * _rotr - rotates the stack to the bottom.
 * @stack: pointer to top of the stack
 * @line_number: number of line to be executed
 * Return: Nothing
 */
void _rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *ptr = *stack;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->prev->next = NULL;
	ptr->prev = NULL;
	ptr->next = *stack;
	(*stack)->prev = ptr;
	*stack = ptr;
}

/**
 * _queue - convert mode from stack to queue
 * @stack: pointer to top of the stack
 * @line_number: number of line to be executed
 * Return: Nothing
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL || (*stack)->next == NULL)
		return;
	_rotl(stack, line_number);
}
