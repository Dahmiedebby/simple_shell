#include "main.h"

/**
* calcchar -  auxilary function
* Description: This program calculates the number of characters
* @s: 1 param
* @t: 2 param
* @delimeter: 3 param
*  Return: Always 0 (Success)
*/

int calcchar(char *s, __attribute__((unused)) int  *t, char delimeter)
{
	int charcount = 0;

	while (s[*t] != '\0')
	{
		if ((*(s + *t) == delimeter) && (*t >= 1) && (*(s + *t - 1) != delimeter))
		{
			return (charcount);
		}
		else if (*(s + *t) != delimeter)
			charcount++;
		*t = 1 + *t;
	}
	return (charcount);
}
/**
* calword -  Word couter auxilary function
* Description: this function calculate the number of word in a sring
* @s: 1 param
* @delimeter: 2 param
*  Return: Always 0 (Success)
*/

int calword(char *s, char delimeter)
{
	int t = 0, wrd = 0;

	if (s == NULL)
		return (0);
	if (s[0] == '\0')
		return (0);
	while (*(s + t) != '\0')
	{
		if (*(s + t) == delimeter && t >= 1)
		{
			if (*(s + t - 1) != delimeter)
			{
				wrd++;
			}
		}
		t++;
	}
	if (t > 0 && *(s + t - 1) != delimeter)
		wrd++;
	return (wrd);
}

/**
* strtow -  Entrypoint
* Description: The program's description _strlen
* @str: 1 param
* @delimeter: 2 parameter
*  Return: Always 0 (Success)
*/
char **strtow(char *str, char delimeter)
{
	int wordcount, charcount = 0, t = 0;
	int num = 0, i;
	char **allstr = NULL;

	wordcount = calword(str, delimeter);
	if (wordcount == 0)
		return (NULL);
	allstr = (char **)malloc((1 + wordcount) * sizeof(char *));
	if (allstr)
	{
		for (num = 0; num < wordcount; num++)
		{
			if (*(str + t) == '\0')
				return (allstr);
			charcount = calcchar(str, &t, delimeter);
			if (charcount != 0)
			{
				allstr[num] = (char *) malloc(sizeof(char) * charcount + 1);
				if (allstr[num] == NULL && num != 0)
				{
					while (num >= 0)
						free(allstr[num--]);
					free(allstr);
					return (NULL);
				}
				for (i = 0; i < charcount; i++)
					allstr[num][i] = *(str + t - charcount + i);
				allstr[num][i] = '\0';
			}
			t++;
		}
		allstr[num] = NULL;
		return (allstr);
	}
	return (allstr);
}
