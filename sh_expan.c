#include "shell.h"

/**
 * buffer_add - add string at end of the buffer
 * @buffer: buffer to be filled
 * @str_add: string to be copied into the buffer
 *
 * Return: nothing, but sets errno.
 */
int buffer_add(char *buffer, char *str_add)
{
	int len, i;

	len = _strlen(buffer);
	for (i = 0; str_add[i]; i++)
	{
		buffer[len + i] = str_add[i];
	}
	buffer[len + i] = '\0';
	return (len + i);

}

/**
 * _expvar - this expands the variables
 * @data: a pointer to a struct of the shell prog's data
 *
 * Return: nothing, but sets errno.
 */
void _expvar(dat_t *data)
{
	int i, j;
	char line[BUFFSIZE] = {0}, expansion[BUFFSIZE] = {'\0'}, *tmp;

	if (data->lin == NULL)
		return;
	buffer_add(line, data->lin);
	for (i = 0; line[i]; i++)
		if (line[i] == '#')
			line[i--] = '\0';
		else if (line[i] == '$' && line[i + 1] == '?')
		{
			line[i] = '\0';
			_itoa(errno, expansion, 10);
			buffer_add(line, expansion);
			buffer_add(line, data->lin + i + 2);
		}
		else if (line[i] == '$' && line[i + 1] == '$')
		{
			line[i] = '\0';
			_itoa(getpid(), expansion, 10);
			buffer_add(line, expansion);
			buffer_add(line, data->lin + i + 2);
		}
		else if (line[i] == '$' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			continue;
		else if (line[i] == '$')
		{
			for (j = 1; line[i + j] && line[i + j] != ' '; j++)
				expansion[j - 1] = line[i + j];
			tmp = _envpath(expansion, data);
			line[i] = '\0', expansion[0] = '\0';
			buffer_add(expansion, line + i + j);
			tmp ? buffer_add(line, tmp) : 1;
			buffer_add(line, expansion);
		}
	if (!_strncmp(data->lin, line, 0))
	{
		free(data->lin);
		data->lin = _strdup(line);
	}
}

/**
 * _expalias - expans aliases
 * @data: a pointer to a struct of the program's data
 *
 * Return: nothing, but sets errno.
 */
void _expalias(dat_t *data)
{
	int i, j, incr = 0;
	char line[BUFFSIZE] = {0}, expansion[BUFFSIZE] = {'\0'}, *tmp;

	if (data->lin == NULL)
		return;

	buffer_add(line, data->lin);

	for (i = 0; line[i]; i++)
	{
		for (j = 0; line[i + j] && line[i + j] != ' '; j++)
			expansion[j] = line[i + j];
		expansion[j] = '\0';

		tmp = _getalias(data, expansion);
		if (tmp)
		{
			expansion[0] = '\0';
			buffer_add(expansion, line + i + j);
			line[i] = '\0';
			buffer_add(line, tmp);
			line[_strlen(line)] = '\0';
			buffer_add(line, expansion);
			incr = 1;
		}
		break;
	}
	if (incr)
	{
		free(data->lin);
		data->lin = _strdup(line);
	}
}
