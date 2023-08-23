#include "shell.h"

/**
 * _strdup - this duplicates a string
 * @str: string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(char *str)
{
	int ln = 0, i;
	char *temp;

	if (str == NULL)
		return (NULL);

	while (str[ln] != '\0')
		ln++;
	temp = malloc(sizeof(char) * (ln + 1));
	if (temp == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}
	for (i = 0; i <= ln; i++)
		temp[i] = str[i];
	return (temp);
}
