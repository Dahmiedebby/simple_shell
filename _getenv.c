#include "shell.h"

/**
 * _envpath - gets the value of an environ variable
 * @path: the environment variable of interest
 * @data: struct of the program's data
 * Return: a pointer to the path of the env var or NULL if it doesn't exist
 */
char *_envpath(char *path, dat_t *data)
{
	int i, path_len = 0;

	/* validate the arguments */
	if (path == NULL || data->env == NULL)
		return (NULL);

	/* get the len of the var requested */
	path_len = _strlen(path);

	for (i = 0; data->env[i]; i++)
	{/* Iterates through the environ and check for matchs in env */
		if (_strncmp(path, data->env[i], path_len) &&
		 data->env[i][path_len] == '=')
		{/* returns the value of the path NAME= if found*/
			return (data->env[i] + path_len + 1);
		}
	}
	/* returns NULL if otherwise */
	return (NULL);
}

/**
 * _envsetpath - overwrite the value of the environ var
 * or create it if does not exist.
 * @path: name of the variable to set
 * @val: new value
 * @data: struct of the program's data
 * Return: 1 if NULL, 2 if error or 0 if sucess.
 */
int _envsetpath(char *path, char *val, dat_t *data)
{
	int i, path_len = 0, new_path = 1;

	/* validate the arguments */
	if (path == NULL || val == NULL || data->env == NULL)
		return (1);

	/* obtains the leng of the variable requested */
	path_len = _strlen(path);

	for (i = 0; data->env[i]; i++)
	{/* Iterates through the environ and check for matches the env */
		if (_strncmp(path, data->env[i], path_len) &&
		 data->env[i][path_len] == '=')
		{/* If key already exists */
			new_path = 0;
			/* free the entire var */
			free(data->env[i]);
			break;
		}
	}
	/* make an string of the form key=value */
	data->env[i] = _strcat(_strdup(path), "=");
	data->env[i] = _strcat(data->env[i], val);

	if (new_path)
	{/* if the variable is new, it is create at end of actual list and we need*/
	/* to put the NULL value in the next position */
		data->env[i + 1] = NULL;
	}
	return (0);
}

/**
 * _envrempath - remove a path from the environment
 * @path: the path to remove
 * @data: the sructure of the prog's data
 * Return: 1 if the key was removed, 0 if the key does not exist;
 */
int _envrempath(char *path, dat_t *data)
{
	int i, path_len = 0;

	/* validate the arguments */
	if (path == NULL || data->env == NULL)
		return (0);

	/* obtains the leng of the variable requested */
	path_len = _strlen(path);

	for (i = 0; data->env[i]; i++)
	{/* iterates through the environ and checks for matches */
		if (_strncmp(path, data->env[i], path_len) &&
		 data->env[i][path_len] == '=')
		{/* if key already exists, remove them */
			free(data->env[i]);

			i++;
			for (; data->env[i]; i++)
			{
				data->env[i - 1] = data->env[i];
			}
			/* put the NULL value at the new end of the list */
			data->env[i - 1] = NULL;
			return (1);
		}
	}
	return (0);
}


/**
 * _printenv - prints the current environ
 * @data: struct for the prog's data
 * Return: void
 */
void _printenv(dat_t *data)
{
	int x;

	for (x = 0; data->env[x]; x++)
	{
		sh_print(data->env[x]);
		sh_print("\n");
	}
}
