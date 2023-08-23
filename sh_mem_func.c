#include "shell.h"

/**
 * free_data - frees data in the loop
 * @data: struct of the shell prog's data
 *
 * Return: void
 */
void free_data(dat_t *data)
{
	if (data->toks)
		free_ptr_array(data->toks);
	if (data->lin)
		free(data->lin);
	if (data->args)
		free(data->args);

	data->lin = NULL;
	data->args = NULL;
	data->toks = NULL;
}

/**
 * freemor_data - frees all data in the loop
 * @data: struct of the shell prog's data
 *
 * Return: void
 */
void freemor_data(dat_t *data)
{
	if (data->fd != 0)
	{
		if (close(data->fd))
			perror(data->av);
	}
	free_data(data);
	free_ptr_array(data->env);
	free_ptr_array(data->ls_alias);
}

/**
 * free_ptr_array - frees each pointer array
 * @dirs: pointers to the dirs
 * Return: nothing
 */
void free_ptr_array(char **dirs)
{
	int i;

	if (dirs != NULL)
	{
		for (i = 0; dirs[i]; i++)
			free(dirs[i]);

		free(dirs);
		dirs = NULL;
	}
}
