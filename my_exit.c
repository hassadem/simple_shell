#include "shell.h"

/**
 * shellexit - this is the function to exit shell for task 4
 * @status: the parameter for the exit status
 *
 * Return: return 0 when success
 */

void shellexit(int status)
{
	if (status == 0)
		exit(EXIT_SUCCESS);
	else
		exit(status);
}

/**
 * implementExitCommand - the function to exit the shell
 * @line: the parameter to check for the client input
 *
 * Return: return 1 if the command works else return 98
 */

int implementExitCommand(char *line)
{
	char *token, *line_copy;
	int status;

	line_copy = strdup(line);

	if (line_copy == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}

	token = strtok(line_copy, " ");

	if (token != NULL && strcmp(token, "exit") == 0)
	{
		token = strtok(NULL, " ");
		status = (token != NULL) ? atoi(token) : 0;
		shellexit(status);
		return (1);
	}
	free(line_copy);
	return (98);

}
