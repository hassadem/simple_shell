#include "shell.h"

/**
 * new_process - function to create a new process
 * @args: parameter for the array of string that contains command
 *
 * Return: 1 if success, 0 otherwise.
 */

int new_process(char **args)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid ==  0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("error in new_process: child process");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("error in new_process: forking");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (-1);
}
