#include "shell.h"

/**
 *_execute - ...
 *@command: ...
 *@argv: ..
 *@idx: ...
 *Return: status of the child
 */
int _execute(char **command, char **argv, int idx)
{
	char *fullcmd;
	pid_t child;
	int status;

	fullcmd = _getpath(command[0]);
	if (!fullcmd)
	{
		printerror(argv[0], command[0], idx);
		free_array(command);
		return (127);
	}

	child = fork();
	if (child == 0)
	{
		if (execve(fullcmd, command, environ) == -1)
		{
			free(fullcmd), fullcmd = NULL;
			free_array(command);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free_array(command);
		free(fullcmd), fullcmd = NULL;
	}

	return (WEXITSTATUS(status));
}
