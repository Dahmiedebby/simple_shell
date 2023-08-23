#include "shell.h"

/**
 * bn_list - search for match and execute the given builtin
 * @data: structure of the program's data
 *
 * Return: the funct executed if there is a match, or -1 otherwise
 **/
int bn_list(dat_t *data)
{
	int i;
	bn_t bins[] = {
		{"exit", bn_exit},
		{"help", bn_help},
		{"cd", bn_cd},
		{"alias", bn_alias},
		{"env", bn_env},
		{"setenv", bn_setenv},
		{"unsetenv", bn_unsetenv},
		{NULL, NULL}
	};

	for (i = 0; bins[i].nam != NULL; i++)
	{
/* Is there is a match between the given command and a bn_t*/
		if (_strncmp(bins[i].nam, data->args, 0))
		{
			return (bins[i].funt(data));
		}
/*if no match return -1 */
	}
	return (-1);
}
