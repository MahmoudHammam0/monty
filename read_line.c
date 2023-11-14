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
	num = atoi(token);
	free(line), line = NULL;
	fclose(f);
	return (num);
}
