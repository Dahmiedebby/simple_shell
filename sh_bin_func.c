#include "shell.h"

/**
 * bn_env - shows the env where the shell runs
 * @data: struct for the program's data
 * Return: 0 (sucess), or other number if its declared in the args
 */
int bn_env(dat_t *data)
{
	int i;
	char name[70] = {'\0'};
	char *_varcpy = NULL;

	if (data->toks[1] == NULL)
		_printenv(data);
	else
	{
		for (i = 0; data->toks[1][i]; i++)
		{/* checks if exists a char = */
			if (data->toks[1][i] == '=')
			{/* checks if exists a var with the same name and change its value*/
			/* temporally */
				_varcpy = _strdup(_envpath(name, data));
				if (_varcpy != NULL)
					_envsetpath(name, data->toks[1] + i + 1, data);

				/* print the environ */
				_printenv(data);
				if (_envpath(name, data) == NULL)
				{
					sh_print(data->toks[1]);
					sh_print("\n");
				}
				else
				{/* returns the old value of the var*/
					_envsetpath(name, _varcpy, data);
					free(_varcpy);
				}
				return (0);
			}
			name[i] = data->toks[1][i];
		}
		errno = 2;
		perror(data->args);
		errno = 127;
	}
	return (0);
}

/**
 * bn_setenv - this sets the env var
 * @data: struct for the program's data
 * Return: 0 if sucess, or other number if its declared in the arguments
 */
int bn_setenv(dat_t *data)
{
	if (data->toks[1] == NULL || data->toks[2] == NULL)
		return (0);
	if (data->toks[3] != NULL)
	{
		errno = E2BIG;
		perror(data->args);
		return (5);
	}

	_envsetpath(data->toks[1], data->toks[2], data);

	return (0);
}

/**
 * bn_unsetenv - removes the env var.
 * @data: struct for the program's data'
 * Return: ..
 */
int bn_unsetenv(dat_t *data)
{
	if (data->toks[1] == NULL)
		return (0);
	if (data->toks[2] != NULL)
	{
		errno = E2BIG;
		perror(data->args);
		return (5);
	}
	_envrempath(data->toks[1], data);

	return (0);
}
