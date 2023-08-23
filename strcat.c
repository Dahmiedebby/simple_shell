#include <stdlib.h>
#include <time.h>
#include "main.h"

/**
* _strcat -  Entrypoint
* Description: The program's description _strcat
* @dest : 1 param
* @src : 2 parameter
*  Return: Always 0 (Success)
*/

char *_strcat(char *dest, char *src)
{
	int i = 0, len_dest, len_src;
	char *tmpstr = NULL, *destr = NULL;

	tmpstr = _strdup(dest);
	len_dest = _strlen(tmpstr);
	len_src = _strlen(src);
	if (tmpstr[len_dest - 1] != '/')
	{
		tmpstr = _realloc(tmpstr, len_dest, len_dest + 1);
		tmpstr[len_dest] = '/';
		tmpstr[len_dest + 1] = '\0';
		len_dest++;
	}
	destr = malloc(sizeof(char) * (len_dest + len_src + 1));
	while (*(tmpstr + i) != '\0')
	{
		*(destr + i) = *(tmpstr + i);
		i++;
	}
	i = 0;
	while (*(src + i) != '\0')
	{
		*(destr + (len_dest + i)) = *(src + i);
		i++;
	}
	*(destr + (len_dest + len_src)) = '\0';
	free(tmpstr);
	return (destr);
}
