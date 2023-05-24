#include "shell.h"

/**
 * main - this the function to prompt user to write to the console
 * @argc: the function for the position of the array element
 * @arg: parameters for sting array
 *
 * Return: if successful return 1 andi if fail retun 98
 */

int main(int argc, char **arg)
{
	char *token;
	char *args[256];
	int argIndex = 0;
	pid_t pid = fork();
	char *prompt = "(USER) $ ";
	char *lineptr;
	size_t i = 0;
	ssize_t myChar;
	(void)argc;
	(void)arg;

	while (1)
	{
		printf("%s", prompt);
		myChar = getline(&lineptr, &i, stdin);
		if (myChar == -1)
		{
			printf("Exit My shell\n");
			break;
		}
		lineptr[strcspn(lineptr, "\nn")] = '\0';
		token = strtok(lineptr, " ");
		while (token != NULL && argIndex < 255)
		{
			args[argIndex++] = token;
			token = strtok(NULL, " ");
		}
		args[argIndex] = NULL;
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			execvp(args[0], args);
			perror("execvp");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
	}
	free(lineptr);
	return (0);
}
