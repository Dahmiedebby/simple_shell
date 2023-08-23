#include "main.h"


/**
 * shell_prompt -  shell_prompt function that handles shell prompt
 * @i: The number of lines
 * @buffer_size: The buffer size
 * Return: Always void
 **/
void shell_prompt(size_t *buffer_size, size_t *i)
{
	*buffer_size = 0;
	*i = 1 + *i;
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", _strlen("$ "));
		fflush(stdout);
	}
}



/**
 * full_of_char -  Test if string is full of char '\t'
 * @str: size_t inisialised with
 * @c: char var
 * Return: Always void
 **/

int full_of_char(char *str, char c)
{
	int i = 0;

	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] == c)
	{
		i++;
	}
	if (str[i] == '\n')
	{
		i++;
	}
	return (_strlen(str) - i);
}

/**
 * get_line_tester -  get_line_tester function that exit
 * @line: size_t inisialised with
 * @tmp: character pointer
 * @numberchar: The number of char
 * @path: The path variable
 * @status: Exit stat
 * Return: Always void
 **/
int get_line_tester(int numberchar, int status, char *line,
char **tmp, char **path)
{
	if (numberchar == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			free_path(path);
			free(line);
			errno = 0;
			exit(EXIT_SUCCESS);
		}
		else
		{
		free_path(path);
		free(line);
		exit(status);
		}
	}
	if (numberchar == 1 || numberchar == 0)
	{
		free_path(path);
		free(line);
		line = NULL;
		return (1);
	}
	if (!full_of_char(line, '\t'))
	{
		free(line);
		line = NULL;
		return (1);
	}
	*tmp = _strncpy(*tmp, line, _strlen(line) - 1);
	return (numberchar);
}
