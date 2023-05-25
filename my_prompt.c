#include "shell.h"

/**
 * my_interactive_shell - function to check if the shell is been interactive
 *
 * Return: void
 */
void my_interactive_shell(void)
{
	char *line;
	char **arg;
	int status = -1;

	do {
		printf("simple_prompt$ ");
		line = read_line();
		arg = split_line(line);
		status = execute_args(arg);
		free(line);
		free(arg);
		if (status >= 0)
		{
			exit(status);
		}
	} while (status == -1);
}
