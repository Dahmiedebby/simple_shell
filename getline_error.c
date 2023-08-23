#include "main.h"

/**
 * getline_error -  getline_erro function that exit
 * @_st: 1  parameter
 * @line: 2 parameter
 * @tab: 3 param
 * @path: 4 param
 * Return: always void
 **/
void getline_error(char *_st, char *line, char **tab, char **path)
{
	(void) _st, (void) line, (void)tab;
	free_memory(NULL, _st, line, tab);
	free_path(path);
	path = NULL;
	exit(1);
}
/**
 * free_memory - Free memory
 * @tmp: 1 param
 * @_st: 2 param
 * @line: 3 param
 * @tab: 4 param
 * Return: always void
 **/

void free_memory(char *tmp, char *_st, char *line, char **tab)
{
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
	if (_st)
	{
		free(_st);
		_st = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
	if (tab)
		free_grid(tab);
}

/**
 * write_error - Write error
 * @filename: Second parameter
 * Return: always void
 **/
void write_error(char *filename)
{
	write(STDERR_FILENO, filename, _strlen(filename));
	write(STDERR_FILENO, ": No such file or directory\n",
	 _strlen(": No such file or directory\n"));
}
