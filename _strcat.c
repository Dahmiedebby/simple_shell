#include "shell.h"

/**
 * _strcat - this concatenates two strings
 * @des: the first string
 * @src: the second string
 *
 * Return: the concatenated string
 */
char *_strcat(char *des, char *src)
{
	char *res;
	int j = 0, i = 0;

	if (des == NULL)
		des = "";
	j = _strlen(des);

	if (src == NULL)
		src = "";
	i = _strlen(src);

	res = malloc(sizeof(char) * (j + i + 1));
	if (res == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}

	for (j = 0; des[j] != '\0'; j++)
		res[j] = des[j];
	free(des);


	for (i = 0; src[i] != '\0'; i++)
	{
		res[i] = src[i];
		i++;
	}

	res[j] = '\0';
	return (res);
}
