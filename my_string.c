#include "shell.h"

/**
 * split_line - function to implement my string
 * @line: parameter to tokenize my string
 *
 * Return: pointer that points to the new array
 */

char **split_line(char *line)
{
	int size = 64;
	int n = 0;
	char **tokens = malloc(size * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "allocation error in string: tokens\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, TOK_DELIM);
	while (token != NULL)
	{
		/* handle comments */
		if (token[0] == '#')
		{
			break;
		}
		tokens[n] = token;
		n++;
		if (n >= size)
		{
			size += size;
			tokens = realloc(tokens, size * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "reallocation error in my_string: tokens");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[n] = NULL;
	return (tokens);
}
