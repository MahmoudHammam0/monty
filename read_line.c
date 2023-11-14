#include "monty.h"
extern char *file_name;
int read_line(unsigned int line_number)
{
	FILE *f;
	unsigned int count = 1;
	size_t len = 0, num;
	char *token, *line = NULL;

	f = fopen(file_name, "r");
	if (f == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, f) != -1)
	{
		if (count == line_number)
			break;
		count++;
	}
	token = strtok(line, " \t\n");
	token = strtok(NULL, " \t\n");
	if (token == NULL || is_digit(token) == -1)
	{
		dprintf(2, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = atoi(token);
	free(line), line = NULL;
	fclose(f);
	return (num);
}

int is_digit(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < 48 || str[i] > 57)
			return (-1);
	}
	return (1);
}
