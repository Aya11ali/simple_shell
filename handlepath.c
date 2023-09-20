#include "shell.h"

/**
 *is_absolute_path - entry point
 *@command: ...
 *Return: string
 */
char *is_absolute_path(char *command)
{
	struct stat st;
	int i;

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)
				return (_strdup(command));
			return (NULL);
		}
	}

	return (NULL);
}

/**
 *find_executable_path - entry point
 *@command: ...
 *Return: string
 */
char *find_executable_path(char *command)
{
	char *path_env, *fullcom, *dir;
	struct stat st;

	path_env = _getenv("PATH");
	if (!path_env)
		return (NULL);

	dir = strtok(path_env, ":");
	while (dir)
	{
		fullcom = malloc(_strlen(dir) + _strlen(command) + 2);
		if (fullcom)
		{
			_strcpy(fullcom, dir);
			_strcat(fullcom, "/");
			_strcat(fullcom, command);
			if (stat(fullcom, &st) == 0)
			{
				free(path_env);
				return (fullcom);
			}

			free(fullcom);
			dir = strtok(NULL, ":");
		}
	}

	free(path_env);
	return (NULL);
}

/**
 *_getpath - entry point
 *@command: ...
 *Return: string
 */
char *_getpath(char *command)
{
	char *abs_path;

	abs_path = is_absolute_path(command);
	if (abs_path)
		return (abs_path);
	return (find_executable_path(command));
}
