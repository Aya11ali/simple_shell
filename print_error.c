#include "shell.h"

/**
 *printerror - ..
 *@name: ...
 *@cmd: ..
 *@ind: ..
 *Return: void
 */
void printerror(char *name, char *cmd, int ind)
{
	char *index, mssg[] = ": not found\n";

	index = _itoa(ind);
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, mssg, _strlen(mssg));
	free(index);
}

/**
 *_itoa - ..
 *@n: ...
 *Return: string
 */
char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}

	buffer[i] = '\0';
	reverse_string(buffer, i);
	return (_strdup(buffer));
}
