#include "shell.h"

/**
 * read_line - function to read user input
 *
 * Return: pointer that points to a string with the line content
 */

char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(line);
			perror("error when reading the command from stdin");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
