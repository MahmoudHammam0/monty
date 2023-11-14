#include "monty.h"

char *file_name;

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
	char *line = NULL;
	size_t length_line = 0;
	stack_t *stack = NULL;
	unsigned int line_number = 1;
	
	file_name = argv[1];
	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	f = fopen(file_name, "r");
	if (f == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &length_line, f) != -1)
	{
		execute_command(line, &stack, line_number);
		line_number++;
	}
	fclose(f);
	free(line), line = NULL;
	_free_stack(stack);
	return (0);
}
