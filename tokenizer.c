#include "shell.h"

/**
 *tokenizer - ...
 *@line: ..
 *Return: string
 */
char **tokenizer(char *line)
{
	char *token = NULL, *tmp = NULL;
	char **command = NULL;
	int c = 0, i = 0;

	if (!line)
		return (NULL);
	tmp = _strdup(line);
	token = strtok(tmp, DELIM);
	if (token == NULL)
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}

	while (token)
	{
		c++;
		token = strtok(NULL, DELIM);
	}

	free(tmp), tmp = NULL;

	command = malloc(sizeof(char *) * (c + 1));
	if (!command)
	{
		free(line);
		return (NULL);
	}

	token = strtok(line, DELIM);
	while (token)
	{
		command[i] = token;
		token = strtok(NULL, DELIM);
		i++;
	}

	free(line), line = NULL;
	command[i] = NULL;
	return (command);
}
