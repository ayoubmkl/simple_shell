#include "shell.h"
/**
 * _strlen:length of a string
 * @s:its a string
 * Return: length
 */
int _strlen(char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}
