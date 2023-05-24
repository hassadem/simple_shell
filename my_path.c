#include "shell.h"

/**
* handlePath - function for path implementation
* @prompt: input to check for the path
* @envp: pointer to environment variable
*
* Return: (0)
*/

void handlePath(char *prompt, char **envp)
{
	int my_path = 0;
	size_t n;

	for (n = 0; n < strlen(prompt); n++)

	{
		if (prompt[n] == '/')
		{
			my_path = 1;
			break;
		}
	}

	if (!my_path)
	{
		char *path_env = getenv(envp, "PATH");
		char *path_token = strtok(path_env, ":");

		while (path_token != NULL)

		{
			char *prompt_path = malloc(strlen(path_token) + strlen(prompt) + 2);

			sprintf(prompt_path, "%s/%s", path_token, prompt);

			if (access(prompt_path, X_OK) == 0)

			{
				strcpy(prompt, prompt_path);
				free(prompt_path);
				return;
			}

			free(prompt_path);
			path_token = strtok(NULL, ":");
		}
	}
}
