#include "shell.h"

/**
 * read_stream - function to read a line
 *
 * Return: pointer that points the the read line
 */

char *read_stream(void)
{
	int bufsize = 1024;
	int n = 0;
	char *line = malloc(sizeof(char) * bufsize);
	int character;
	if (line == NULL)
	{
		fprintf(stderr, "allocation error in read_stream");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		character = getchar(); /* read first char from stream */
		if (character == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else if (character == '\n')
		{
			line[n] = '\0';
			return (line);
		}
		else
		{
			line[n] = character;
		}
		n++;
		if (n >= bufsize)
		{
			bufsize += bufsize;
			line = realloc(line, bufsize);
			if (line == NULL)
			{
				fprintf(stderr, "reallocation error in read_stream");
				exit(EXIT_FAILURE);
			}
		}
	}
}

