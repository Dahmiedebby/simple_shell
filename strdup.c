#include <stdlib.h>
#include <time.h>
#include "main.h"


/**
* _strdup -  Entrypoint
* Description: The program's description _strdup
* @str : 1 parameter
*  Return: Always 0 (Success)
*/
char *_strdup(char *str)
{
	char *s;
	int i = 0;

	if (str == NULL)
		return (NULL);
	s = malloc(sizeof(char) * (_strlen(str) + 1));
	if (s)
	{
		for (; i < _strlen(str); i++)
		{
			*(s + i) = *(str + i);
		}
		s[i] = '\0';
	return (s);
	}
	free(s);
	return (NULL);
}
