#include <stdlib.h>
#include <time.h>
#include "main.h"

/**
* _strncpy -  Entrypoint
* Description: the program's description _strcpy
* @dest : param 1
* @src : param 2
* @n : param
*  Return: Always 0 (Success)
*/

char *_strncpy(char *dest, char *src, int n)
{
	int t = 0;

	if (n > 0)
		dest = malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (NULL);
	if (src)
		while ((*(src + t) != '\0') && t < n)
		{
			*(dest + t) = *(src + t);
			t++;
		}
	while (t <= n)
	{
		*(dest + t) = '\0';
		t++;
	}
	return (dest);
}
