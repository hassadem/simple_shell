#include "shell.h"

/**
 * my_cd - fucntion for Implementation of my_cd function
 * @args: the command parameters
 *
 * Return: 1 on success, 0 otherwise
 */

int my_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "cd: expected argument to \"cd\"\n");
	} else
	{
		if (chdir(args[1]) != 0)
		{
			perror("cd");
		}
	}
	return (1);
}

/**
 * my_env - function for Implementation of my_env function
 * @args: the command parameters
 *
 * Return: 1 on success, 0 otherwise
 */
int my_env()
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
	return (1);
}

/**
 * my_help - fucntion for Implementation of my_help function
 * @args: the command parameters
 *
 * Return: 1 on success, 0 otherwise
 */

int my_help()
{
	printf("Help information for your shell:\n");
	return (1);
}


/**
 * my_exit - function exit implementation
 * @args: the command parameters
 *
 * Return: 1 on success, 0 otherwise
 */
int my_exit(char **args)
{
	char **temp = args;

	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(args);
	exit(0);
	return (1);
}

/**
 * execute_args - function to test if the command is been implement
 * @args: the command parameters
 *
 * Return: 1 on sucess, 98 otherwise
 */

int execute_args(char **args)
{
	char *builtin_func_list[] = {
		"cd",
		"env",
		"help",
		"exit",
		NULL
	};
	int (*builtin_func[])(char **) = {
		&my_cd,
		&my_env,
		&my_help,
		&my_exit,
		NULL
	};
	size_t n = 0;

	if (args[0] == NULL)
	{
		return (-1);
	}
	for (; n < sizeof(builtin_func_list) / sizeof(char *); n++)
	{
		if (strcmp(args[0], builtin_func_list[n]) == 0)
		{
			return ((*builtin_func[n])(args));
		}
	}
	return (new_process(args));
}
