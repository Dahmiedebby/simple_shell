#include "main.h"


/**
 * _stat -  SIGINT handler
 * @command: 1 parameter
 * Return: Always 0
 **/

int _stat(char *command)
{
	struct stat st;

	return (stat(command, &st));
}
