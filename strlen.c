#include "shell.h"

/**
 * _strlen - the length of the string
 * @str: pointer to the string
 *
 * Return: length of string
 */
int _strlen(char *str)
{
	int ln = 0;

	if (str == NULL)
		return (0);

	while (str[ln] != '\0')
		ln++;

	return (ln);
}
