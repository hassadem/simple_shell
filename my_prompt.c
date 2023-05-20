#include "shell.h"

/**
 * main - this the function to prompt user to write to the console
 * @ac: the function for the position of the array element
 *
 * Return: if successful return 1 andi if fail retun 98
 */

int main(int argc, char **arg)
{
	char *prompt = "(USER) $ ";
	char *lineptr;
	size_t i = 0;

	(void)argc; (void)arg;

	while(1)
	{
		printf("%s", prompt);
		getline(&lineptr, &i, stdin);
		printf("%s\n", lineptr);
		
		free(lineptr);
	}
	return (0);
}
