#include "shell.h"

/**
 *read_line - ...
 *Return: string or null
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	size_t n;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	n = getline(&line, &len, stdin);
	if (n == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}
