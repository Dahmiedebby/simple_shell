#include <stdlib.h>
#include <time.h>
#include "main.h"

/**
* _atoi -  Entrypoint
* Description: The program's description _atoi
* @str : 1 parameter
*  Return: Always 0 (Success)
*/

int _atoi(char *str)
{
	int result, puiss, i = 0, j = 0;

	result = 0;
	puiss = 1;
	while (('-' == *(str + j)) || (*(str + j) == '+'))
	{
		if (*str == '-')
			puiss = puiss * -1;
		j++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
		if (*(str + i) < '0' || *(str + i) > '9' || *(str + i) == '\0')
		break;
	}
	return (result * puiss);
}
