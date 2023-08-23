#include "shell.h"

/**
 * tokenize - this function separate the string using a delimiter
 * @data: a pointer to the program's data
 * Return: an array of the different parts of the string
 */
void tokenize(dat_t *data)
{
	char *del = " \t";
	int i, j, count = 2, len;

	len = _strlen(data->lin);
	if (len)
	{
		if (data->lin[len - 1] == '\n')
			data->lin[len - 1] = '\0';
	}

	for (i = 0; data->lin[i]; i++)
	{
		for (j = 0; del[j]; j++)
		{
			if (data->lin[i] == del[j])
				count++;
		}
	}

	data->toks = malloc(count * sizeof(char *));
	if (data->toks == NULL)
	{
		perror(data->av);
		exit(errno);
	}
	i = 0;
	data->toks[i] = _strdup(_strtok(data->lin, del));
	data->args = _strdup(data->toks[0]);
	while (data->toks[i++])
	{
		data->toks[i] = _strdup(_strtok(NULL, del));
	}
}
