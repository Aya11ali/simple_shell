#include "shell.h"

/**
 *reverse_string - ...
 *@str: ...
 *@len: ..
 *Return: status of the child
 */
void reverse_string(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}
