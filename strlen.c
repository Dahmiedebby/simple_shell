#include "main.h"

/**
* _strlen -  Entrypoint
* Description: The program's description _strlen
* @s : 1 parameter
* Return: Always 0 (Success)
*/

int _strlen(char *s)
{
	int t = 0, len = 0;

	if (!s)
		return (0);
	while (*(s + t) != '\0')
	{
		len = len + 1;
		t++;
	}
	return (len);
}
