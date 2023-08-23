#include "shell.h"

/**
 * _strtok - tokenises/parses a string following a sep or delim
 * @line: string to be parse
 * @del: list of separator char
 *
 * Return: null terminated token before the sep or del
 * On subsequent call NULL is passed as string
 */
char *_strtok(char *line, char *del)
{
	int x;
	static char *str;
	char *ind;

	if (line != NULL)
		str = line;
	for (; *str != '\0'; str++)
	{
		for (x = 0; del[x] != '\0'; x++)
		{
			if (*str == del[x])
			break;
		}
		if (del[x] == '\0')
			break;
	}
	ind = str;
	if (*ind == '\0')
		return (NULL);
	for (; *str != '\0'; str++)
	{
		for (x = 0; del[x] != '\0'; x++)
		{
			if (*str == del[x])
			{
				*str = '\0';
				str++;
				return (ind);
			}
		}
	}
	return (ind);
}
