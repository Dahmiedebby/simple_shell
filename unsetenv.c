#include "main.h"

/**
 * _unsetenv - Remove env variable
 * @name: name
 * Return: 0
 */

int _unsetenv(const char *name)
{
	char **ch1, **ch2;
	size_t lenght;

	if (name == NULL || *name == '\0' || _strc(name, '=') == 0)
	{
		perror("unsetenv error: invalid arg");
		return (-1);
	}
	lenght = _strlen((char *)name);

	for (ch1 = environ; *ch1 != NULL;)
	{
		if (_strncmp(*ch1, name, lenght) == 0 && (*ch1)[lenght] == '=')
		{
		for (ch2 = ch1; *ch2 != NULL; ch2++)
			_strcpy(*ch2, *(ch2 + 1));
		}
		else
			ch1++;
	}
	return (0);
}

/**
 * *_strncmp - Main function
 * @s1: arg1
 * @s2: arg2
 * @n: ..
 * Return: 0
 **/

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (!s1 || !s2)
		return (124);
	for (i = 0; i < n; i++)
	{
		if (*(s1 + i) != *(s2 + i))
			return (s1[i] - s2[i]);
		if (*(s1 + i) == '\0' || *(s2 + i) == '\0')
			break;
	}
	return (0);
}
