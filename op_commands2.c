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