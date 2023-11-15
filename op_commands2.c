#include "monty.h"

/**
 * _add - adds the top two elements of the stack.
 * @stack: pointer to top of the stack
 * @line_number: number of line to be executed
 * Return: Nothing
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr1 = *stack, *ptr2;
	int num1, num2;

	if (ptr1 == NULL || ptr1->next == NULL)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr2 = ptr1->next;
	num1 = ptr1->n;
	num2 = ptr2->n;
	ptr2->n = num1 + num2;
	ptr2->prev = NULL;
	*stack = ptr2;
	free(ptr1), ptr1 = NULL;
}

/**
 * _sub - subtracts the top element of the stack from the second
 * top element of the stack
 *
 * @stack: pointer to top of the stack
 * @line_number: number of line to be executed
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr1 = *stack, *ptr2;
	int num1, num2;

	if (ptr1 == NULL || ptr1->next == NULL)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr2 = ptr1->next;
	num1 = ptr1->n;
	num2 = ptr2->n;
	ptr2->n = num2 - num1;
	ptr2->prev = NULL;
	*stack = ptr2;
	free(ptr1), ptr1 = NULL;
}

/**
 * _div - divides the second top element of the stack by the top element
 * of the stack
 *
 * @stack: pointer to top of the stack
 * @line_number: number of line to be executed
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr1 = *stack, *ptr2;
	int num1, num2;

	if (ptr1 == NULL || ptr1->next == NULL)
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr2 = ptr1->next;
	num1 = ptr1->n;
	num2 = ptr2->n;
	if (num1 == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr2->n = num2 / num1;
	ptr2->prev = NULL;
	*stack = ptr2;
	free(ptr1), ptr1 = NULL;
}

/**
 * _mul - multiplies the second top element of the stack with the top element
 * of the stack
 *
 * @stack: pointer to top of the stack
 * @line_number: number of line to be executed
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr1 = *stack, *ptr2;
	int num1, num2;

	if (ptr1 == NULL || ptr1->next == NULL)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr2 = ptr1->next;
	num1 = ptr1->n;
	num2 = ptr2->n;
	ptr2->n = num2 * num1;
	ptr2->prev = NULL;
	*stack = ptr2;
	free(ptr1), ptr1 = NULL;
}

/**
 * _mod - computes the rest of the division of the second top element of the
 * stack by the top element of the stack
 *
 * @stack: pointer to top of the stack
 * @line_number: number of line to be executed
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr1 = *stack, *ptr2;
	int num1, num2;

	if (ptr1 == NULL || ptr1->next == NULL)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr2 = ptr1->next;
	num1 = ptr1->n;
	num2 = ptr2->n;
	if (num1 == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr2->n = num2 % num1;
	ptr2->prev = NULL;
	*stack = ptr2;
	free(ptr1), ptr1 = NULL;
}
