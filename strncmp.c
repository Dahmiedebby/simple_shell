#include "shell.h"
/**
 * _strncmp - this compares the first n characters of two strings
 * @s1: first str
 * @s2: second str
 * @n: number of character to be compared
 *
 * Return: 1 if strings are equal or 0 if they differ.
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i;

	if (s1 == NULL && s2 == NULL)
		return (1);

	if (s1 == NULL || s2 == NULL)
		return (0);

	if (n == 0)
	{
		if (_strlen(s1) != _strlen(s2))
			return (0);
		for (i = 0; s1[i]; i++)
		{
			if (s1[i] != s2[i])
				return (0);
		}
		return (1);
	}
	else
	{
		for (i = 0; i < n ; i++)
		{
			if (s1[i] != s2[i])
			return (0);
		}
		return (1);
}
}
