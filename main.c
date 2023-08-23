#include "main.h"




/**
 *sig_handler -  SIGINT handler
 *@signo: 1 param
 * Return: Always 0
 **/
void sig_handler(__attribute__((unused)) int signo)
{
	write(STDOUT_FILENO, "\n$ ", _strlen("\n$ "));
	fflush(stdout);
}
/**
 * main - Entry point
 *@ac: 1 paramter
 *@av: 2 parameter
 * Return: Always 0
 **/

int main(__attribute__((unused))int ac, __attribute__((unused))char **av)
{
	size_t buffer_size = 0, i = 0;
	int numberchar, status = 0, flag = 0;
	char *line = NULL, **tab = NULL, *cmd = NULL, *tmp = NULL, **path = NULL;

	signal(SIGINT, sig_handler);
	while (1)
	{
		path = strtow(_getenv("PATH"), ':');
		shell_prompt(&buffer_size, &i);
		numberchar = getline(&line, &buffer_size, stdin);
		if (get_line_tester(numberchar, status, line, &tmp, path) == 1)
			continue;
		tab = strtow(tmp, ' ');
		if (tab)
		{
			builtin_command(line, tmp, path, tab, av, &flag, &status, i);
			if (flag)
			{
				free_memory(tmp, cmd, line, tab);
				free_path(path);
				continue;
			}
			cmd = _find_command(tab[0], path);
			child(&status, &flag, cmd, line, tab, path);
			if (!flag)
				write_not_found_error(av[0], i, cmd, &status);
		}
		if (tab && !_strncmp(tab[0], cmd, _strlen(cmd)) &&
		access(cmd, X_OK) == 0)
			free_memory(tmp, NULL, line, tab);
		else
			free_memory(tmp, cmd, line, tab);
		free_path(path);
	}
	return (0);
}
