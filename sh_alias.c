#include "shell.h"
/**
 * _printalias - this adds, deletes or shows alias
 * @data: struct for the shell data
 * @alias: name of the alias to be printed
 * Return: 0 (sucess), or other number if declared in the args
 */
int _printalias(dat_t *data, char *alias)
{
	int m, n, len_alias;
	char buffer[250] = {'\0'};

	if (data->ls_alias)
	{
		len_alias = _strlen(alias);
		for (m = 0; data->ls_alias[m]; m++)
		{
			if (!alias || (_strncmp(data->ls_alias[m], alias, len_alias)
				&&	data->ls_alias[m][len_alias] == '='))
			{
				for (n = 0; data->ls_alias[m][n]; n++)
				{
					buffer[n] = data->ls_alias[m][n];
					if (data->ls_alias[m][n] == '=')
						break;
				}
				buffer[n + 1] = '\0';
				buffer_add(buffer, "'");
				buffer_add(buffer, data->ls_alias[m] + n + 1);
				buffer_add(buffer, "'\n");
				sh_print(buffer);
			}
		}
	}
	return (0);
}
/**
 * _getalias - this adds, deletes or shows alias
 * @data: struct for the shell data
 * @name: name of the called alias.
 * Return: 0 (sucess), or otherwise if its declared args is diff number
 */
char *_getalias(dat_t *data, char *name)
{
	int i, len_alias;

	if (name == NULL || data->ls_alias == NULL)
		return (NULL);

	len_alias = _strlen(name);

	for (i = 0; data->ls_alias[i]; i++)
	{/* Iterates through the environ and check for coincidence of the varname */
		if (_strncmp(name, data->ls_alias[i], len_alias) &&
			data->ls_alias[i][len_alias] == '=')
		{/* returns the value of the key NAME=  when find it */
			return (data->ls_alias[i] + len_alias + 1);
		}
	}
	/* returns NULL if did not find it */
	return (NULL);
}

/**
 * _setalias - this adds, or overwrite alias
 * @alias_name: alias to be set in this form (name='value')
 * @data: struct for the shell program's data
 * Return: 0 (sucess), or other number if declared in the args
 */
int _setalias(char *alias_name, dat_t *data)
{
	int x, y;
	char buffer[250] = {'0'}, *tmp = NULL;

	/* validate the arguments */
	if (alias_name == NULL ||  data->ls_alias == NULL)
		return (1);
	/* Iterates alias to find = char */
	for (x = 0; alias_name[x]; x++)
		if (alias_name[x] != '=')
			buffer[x] = alias_name[x];
		else
		{/* search if the value of the alias is another alias */
			tmp = _getalias(data, alias_name + x + 1);
			break;
		}
	for (y = 0; data->ls_alias[y]; y++)
		if (_strncmp(buffer, data->ls_alias[y], x) &&
			data->ls_alias[y][x] == '=')
		{/* if the alias alredy exist */
			free(data->ls_alias[y]);
			break;
		}
	if (tmp)
	{
		buffer_add(buffer, "=");
		buffer_add(buffer, tmp);
		data->ls_alias[y] = _strdup(buffer);
	}
	else
		data->ls_alias[y] = _strdup(alias_name);
	return (0);
}
