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
	while (ptr != NULL)
	{
		dprintf(1, "%d\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
 * _pint - prints the value at the top of the stack, followed by a new line.
 * @stack: pointer to top of the stack
 * @line_number: number of the line to be executed
 * Return: Nothing
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	if (ptr == NULL)
	{
		dprintf(2, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	dprintf(1, "%d\n", ptr->n);
}

/**
 * _pop - removes the top element of the stack.
 * @stack: pointer to top of the stack
 * @line_number: number of line to be executed
 * Return: Nothing
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	if (ptr == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (ptr->next == NULL)
		(*stack) = NULL;
	else
	{
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
	}
	free(ptr), ptr = NULL;
}

/**
 * _swap - swaps the top two elements of the stack.
 * @stack: pointer to top of the stack
 * @line_number: number of the line to be executed
 * Return: Nothing
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr1 = *stack, *ptr2;

	if (ptr1 == NULL || ptr1->next == NULL)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr2 = ptr1->next;
	ptr1->next = ptr2->next;
	ptr1->prev = ptr2;
	ptr2->next = ptr1;
	ptr2->prev = NULL;
	if (ptr1->next != NULL)
		ptr1->next->prev = ptr1;
	*stack = ptr2;
}
