#include <stdlib.h>
#include <time.h>
#include "main.h"

/**
* _strncpy -  entrypoint
* Description: The program's description _strcpy
* @dest : 1 param
* @src : 2 param
* @n : Param
* Return: always 0 (Success)
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
