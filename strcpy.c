#include "shell.h"

/**
 * _strcpy - this copies a string to another
 * @des: string's destination
 * @src: string's source
 *
 * Return: the destination string
 */
char *_strcpy(char *des, char *src)
{
	int n;

	for (n = 0; src[n]; n++)
		des[n] = src[n];
	des[n] = '\0';

	return (des);
}
