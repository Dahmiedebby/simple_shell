#include "main.h"

/**
 * _setenv - set env variable
 * @variable: ..
 * @value: ..
 * @overwrite: 1 or 0
 * Return: -1 if fail, 0 on success
 */
int _setenv(const char *variable, const char *value, int overwrite)
{
	char *val;
	int set_val;

	if (variable == NULL || variable[0] == '\0' ||  _strc(variable, '=') != 0)
	{
		perror("setenv error: invalid variable name");
		return (-1);
	}
	if (_getenv(variable) && overwrite == 0)
	{
		perror("setenv error: variable already exist");
		return (-1);
	}
	val = malloc(_strlen((char *)variable) + _strlen((char *)value) + 2);

	if (val == NULL)
	{
		perror("setenv error: failed memory");
		return (-1);
	}
	_strcpy((char *)val, (char *)variable);
	_strcat((char *)val, "=");
	_strcat((char *)val, (char *)value);

	set_val = putenv(val);

	if (set_val)
	{
		perror("setenv error: failed to set the value");
		free(val);
		return (-1);
	}
	return (0);
}
/**
 * _strc - function
 * @str: string
 * @ch: Character
 * Return: true or false
 */
int _strc(const char *str, char ch)
{
	while (*str != '\0' && *str != ch)
		str++;
	return (*str == ch);

}
/**
 * char *_strcpy - A function that copies the string pointed to by src
 * @dest: Copy to
 * @src: Copy from
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	size_t len = _strlen(src), i;

	if (dest == NULL || src == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
