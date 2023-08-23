#include "main.h"

/**
 * child - child
 * @status: 1
 * @cmd: The command
 * @ln: The string  line readed from getline
 * @tab: The 2 diemension table
 * @path: The environment variable that hold paths
 * @fg: flag indicates if the command is found or not
 * Return: Always void
 **/
void child(int *status, int *fg, char *cmd, char *ln, char **tab, char **path)
{
	int exit_stat;

	if (access(cmd, X_OK) == 0)
	{
		__pid_t pid;

		*fg = 1;
		pid = fork();
		if (pid == -1)
			getline_error(cmd, ln, tab, path);
		if (pid == 0)
			execute(cmd, tab);
		else
		{
			wait(status);
			if (WIFEXITED(*status))
			{
				if (isatty(STDIN_FILENO))
					errno = 0;
				else
				{
					exit_stat = WEXITSTATUS(*status);
					*status = exit_stat;
				}
			}
		}
	}
	else
	{
		*status = 127;
		*fg = 0;
	}

}
