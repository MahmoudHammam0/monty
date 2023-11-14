#include "monty.h"

/**
 * _free_stack - frees the stack
 *
 * @stack: doubly linked list representing a stack_t stack
 */
void _free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
		temp = NULL;
	}
}

/**
 * main - Entry point
 *
 * @argc: number of command line arguments
 * @argv: command line arguments
 *
 * Return: 0 Always
 */
int main(int argc, char *argv[])
{
	FILE *f;
	char *line;
	size_t length_line;
	stack_t *stack;
	unsigned int line_number;

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	f = fopen(argv[2], "r");
	if (f == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &length_line, f) != -1)
	{
		/* execute_command(line, &stack, line_number); */
	}

	fclose(f);
	_free_stack(stack);

	return (0);
}
