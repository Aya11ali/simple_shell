#include "shell.h"

/**
 * _strlen - returns the length of a string.
 * @s: char pointer
 * Return: the length of the string 
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: sec string
 * Return: 0
 */
int _strcmp(char *s1, char *s2)
{
	int nn;
	nn = (int)*s1 - (int)*s2;
	while(*s1)
	{
		if(*s1 != *s2)
			break;
		s1++;
		s2++;
		nn = (int)*s1 - (int)*s2;
	}
	return(nn);
}

/**
 * _strdup - creates an array of chars
 * @str: array size
 * Return: array refrance or NULL
 */
char *_strdup(char *str)
{
	char *ptr;
	int i, len = 0;

	if(str == NULL)
		return(NULL);
	while(*str != '\0')
	{
		len++;
		str++;
	}
	str = str - len;
	ptr = malloc(sizeof(char) * (len + 1));
	if(ptr == NULL)
		return(NULL);
	for(i = 0; i <= len; i++)
		ptr[i] = str[i];
	return (ptr);

}

/**
 * _strcpy - copies the string pointed
 * @dest: char pointer
 * @src: char pointer
 * Return: char pinter
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - concatenates two strings
 * @dest: char pointer left side
 * @src: char pointer right side
 * Return: the length *s
 */
char *_strcat(char *dest, char *src)
{
	int len, i;

	len = _strlen(dest);
	for (i = 0; src[i] != '\0'; i++)
	{
		dest[len + i] = src[i];
	}
	dest[len + i] = '\0';
	return (dest);
}
