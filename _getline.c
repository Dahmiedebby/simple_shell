#include "shell.h"

/**
* _getline - this reads line from the prompt.
* @data: struct for the shell prog's data
*
* Return: lines read.
*/
int _getline(dat_t *data)
{
	char buff[BUFFSIZE] = {'\0'};
	static char *arrcmds[10] = {NULL};
	static char arrops[10] = {'\0'};
	ssize_t _linread, i = 0;

	/* and checks the logical operators */
	if (!arrcmds[0] || (arrops[0] == '&' && errno != 0) ||
		(arrops[0] == '|' && errno == 0))
	{
		/*free the memory allocated in the array if it exists */
		for (i = 0; arrcmds[i]; i++)
		{
			free(arrcmds[i]);
			arrcmds[i] = NULL;
		}

		/* read from the file descriptor int to buff */
		_linread = read(data->fd, &buff, BUFFSIZE - 1);
		if (_linread == 0)
			return (-1);
		/* split lines for \n or ; */
		i = 0;
		do {
			arrcmds[i] = _strdup(_strtok(i ? NULL : buff, "\n;"));
			/*checks and split for && and || operators*/
			i = _chcklogops(arrcmds, i, arrops);
		} while (arrcmds[i++]);
	}

	/*obtains the next command (command 0) and remove it for the array*/
	data->lin = arrcmds[0];
	for (i = 0; arrcmds[i]; i++)
	{
		arrcmds[i] = arrcmds[i + 1];
		arrops[i] = arrops[i + 1];
	}
	return (_strlen(data->lin));
}


/**
* _chcklogops - checks and split && and || operators
* @arrcmds: array of the commands.
* @i: index in the array_commands to be checked
* @arrops: array of the logical operators for each previous command
*
* Return: index of the last command in the array_commands.
*/
int _chcklogops(char *arrcmds[], int i, char arrops[])
{
	int j;
	char *res = NULL;

	/* checks for the & char in the command line*/
	for (j = 0; arrcmds[i] != NULL  && arrcmds[i][j]; j++)
	{
		if (arrcmds[i][j] == '&' && arrcmds[i][j + 1] == '&')
		{
			/* split the line when chars && was found */
			res = arrcmds[i];
			arrcmds[i][j] = '\0';
			arrcmds[i] = _strdup(arrcmds[i]);
			arrcmds[i + 1] = _strdup(res + j + 2);
			i++;
			arrops[i] = '&';
			free(res);
			j = 0;
		}
		if (arrcmds[i][j] == '|' && arrcmds[i][j + 1] == '|')
		{
			/* split the line when chars || was found */
			res = arrcmds[i];
			arrcmds[i][j] = '\0';
			arrcmds[i] = _strdup(arrcmds[i]);
			arrcmds[i + 1] =_strdup(res+j+2);
			i++;
			arrops[i] = '|';
			free(res);
			j = 0;
		}
	}
	return (i);
}
