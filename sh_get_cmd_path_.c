#include "shell.h"

int _chckfile(char *path);

/**
 * search_prog - find a program in path
 * @data: a pointer to the data structure
 *
 * Return: 0 if success, errcode otherwise
 */
int search_prog(dat_t *data)
{
	int i = 0, code = 0;
	char **dirs;

	if (!data->args)
		return (2);

	if (data->args[0] == '/' || data->args[0] == '.')
		return (_chckfile(data->args));

	free(data->toks[0]);
	data->toks[0] = _strcat(_strdup("/"), data->args);
	if (!data->toks[0])
		return (2);

	dirs = parse_path(data);

	if (!dirs || !dirs[0])
	{
		errno = 127;
		return (127);
	}
	for (i = 0; dirs[i]; i++)
	{/* add the func_name to path */
		dirs[i] = _strcat(dirs[i], data->toks[0]);
		code = _chckfile(dirs[i]);
		if (code == 0 || code == 126)
		{
			errno = 0;
			free(data->toks[0]);
			data->toks[0] = _strdup(dirs[i]);
			free_ptr_array(dirs);
			return (code);
		}
	}
	free(data->toks[0]);
	data->toks[0] = NULL;
	free_ptr_array(dirs);
	return (code);
}

/**
 * parse_path - tokenize/parse the path in dirs
 * @data: a pointer to the data struct
 *
 * Return: array of path dirs
 */
char **parse_path(dat_t *data)
{
	int i = 0;
	int counter_dirs = 2;
	char **toks = NULL;
	char *PATH;

	/* get the PATH key*/
	PATH = _envpath("PATH", data);
	if ((PATH == NULL) || PATH[0] == '\0')
	{
		return (NULL);
	}

	PATH = _strdup(PATH);

	/* find the number of directories in the PATH */
	for (i = 0; PATH[i]; i++)
	{
		if (PATH[i] == ':')
			counter_dirs++;
	}

	toks = malloc(sizeof(char *) * counter_dirs);

	/*parse and duplicate each token of path*/
	i = 0;
	toks[i] = _strdup(_strtok(PATH, ":"));
	while (toks[i++])
	{
		toks[i] = _strdup(_strtok(NULL, ":"));
	}

	free(PATH);
	PATH = NULL;
	return (toks);

}

/**
 * _chckfile - checks if file exists.
 * @path: pointer to the full file name
 * Return: 0 on success, or error code if it exists.
 */
int _chckfile(char *path)
{
	struct stat uc;

	if (stat(path, &uc) != -1)
	{
		if (S_ISDIR(uc.st_mode) ||  access(path, X_OK))
		{
			errno = 126;
			return (126);
		}
		return (0);
	}
	/*if non-existence */
	errno = 127;
	return (127);
}
