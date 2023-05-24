#include "shell.h"

/**
 * main- function to handle user input
 * @arg: argument count
 * @argv: argument vector for the array
 * @envp: environment variables
 *
 * Return: (0) success
 */

int main(int arg, char **argv, char **envp)
{
	(void)arg;

	handleUserInput(argv, envp);

	return (0);
}
