#include "main.h"

/**
* _getenv -  auxilatry function
* Description: _getenv read environment variables
* and return the the desired variable
* @name : 1 param
* Return: Always 0 (Success)
**/

char *_getenv(const char *name)
{
	int i = 0, j = 0, len;
	char *var = NULL;

	len = _strlen((char *)name);
	for (i = 0; environ[i] != NULL; i++)
	{
		j = 0;
		while (name[j] != '\0')
		{
			if (environ[i][j] == name[j])
			{
				j++;
			}
			else
				break;
		}
		if (len == j && environ[i][j] == '=')
		{
			var = environ[i] + len + 1;
			break;
		}
	}
	return (var);
}

/**
* print_env -  auxilatry function
* Description: _getenv read environment variables
* and return the the desired variable
* Return: Always 0 (Success)
**/

void print_env(void)
{
	int i = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", _strlen("\n"));
	}
}
