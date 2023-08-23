#include "shell.h"

/**
 * sh_print - this writes an array of chars to STDOUT.
 * @str: pointer to the array of chars
 *
 * Return:  number of bytes writen.
 * -1 is returned on error, and errno is set.
 */
int sh_print(char *str)
{
	return (write(STDOUT_FILENO, str, _strlen(str)));
}

/**
 * she_print - prints array of chars in the STDERR
 * @str: pointer to the array of chars
 *
 * Return: the number of bytes writed or .
 * On error, -1 is returned, and errno is set.
 */
int she_print(char *str)
{
	return (write(STDERR_FILENO, str, _strlen(str)));
}

/**
 * sh_printerror - prints array of chars to the STDERR
 * @data: a pointer to the shell prog's data
 * @errorcode: error code to print
 * Return: the number of bytes writed or .
 * On error, -1 is returned, and errno is set appropriately.
 */
int sh_printerror(int errorcode, dat_t *data)
{
	char str[10] = {'\0'};

	_itoa((long) data->counter, str, 10);

	if (errorcode == 2 || errorcode == 3)
	{
		she_print(data->av);
		she_print(": ");
		she_print(str);
		she_print(": ");
		she_print(data->toks[0]);
		if (errorcode == 2)
			she_print(": Unwanted number: ");
		else
			she_print(": can't cd to ");
		she_print(data->toks[1]);
		she_print("\n");
	}
	else if (errorcode == 127)
	{
		she_print(data->av);
		she_print(": ");
		she_print(str);
		she_print(": ");
		she_print(data->args);
		she_print(": not found\n");
	}
	else if (errorcode == 126)
	{
		she_print(data->av);
		she_print(": ");
		she_print(str);
		she_print(": ");
		she_print(data->args);
		she_print(": Permission not Granted\n");
	}
	return (0);
}
