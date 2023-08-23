#include "shell.h"

/**
 * _strrev - this reverses a string.
 * @str: pointer to string.
 *
 * Return: nothing
 */
void _strrev(char *str)
{

	int i = 0, len = _strlen(str) - 1;
	char kep;

	while (i < len)
	{
		kep = str[i];
		str[i++] = str[len];
		str[len--] = kep;
	}
}
