#include "shell.h"

/**
 *count_tokens - ...
 *@line: ..
 *Return: counter
 */

int count_tokens(char *line)
{
	char *token = NULL, *tmp = NULL;
	int count = 0;

	if (!line)
		return (0);

	tmp = _strdup(line);
	token = strtok(tmp, DELIM);
	if (token == NULL)
	{
		free(tmp), tmp = NULL;
		return (0);
	}

	while (token)
	{
		count++;
		token = strtok(NULL, DELIM);
	}

	free(tmp), tmp = NULL;
	return (count);
}

/**
 *tokenizer - ...
 *@line: ..
 *Return: string
 */

char **tokenizer(char *line)
{
	char *token = NULL;
	char **command = NULL;
	int num_tokens = count_tokens(line);
	int i = 0;

	if (num_tokens == 0)
	{
		free(line), line = NULL;
		return (NULL);
	}

	command = malloc(sizeof(char *) * (num_tokens + 1));
	if (!command)
	{
		free(line), line = NULL;
		return (NULL);
	}

	token = strtok(line, DELIM);
	while (token)
	{
		command[i] = _strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}

	free(line), line = NULL;
	command[i] = NULL;
	return (command);
}

