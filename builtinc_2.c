#include "shell.h"

/**
 * my_non_interactive_shell - unix command line interpreter
 *
 * Return: void
 */

void my_non_interactive_shell(void)
{
	char *line;
	char **args;
	int status = -1;

	do {
		line = read_stream();
		args = split_line(line);
		status = execute_args(args);
		free(line);
		free(args);
		if (status >= 0)
		{
			exit(status);
		}
	} while (status == -1);
}
