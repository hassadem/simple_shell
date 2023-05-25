#include "shell.h"

/**
 * main - function to test for the shell command
 *
 * Return: 0 on success
 */

int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
	my_interactive_shell();
	}
	else
	{
	my_non_interactive_shell();
	}
	return (0);
}
