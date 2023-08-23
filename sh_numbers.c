#include "shell.h"

/**
 * _itoa - converts a number to a string.
 * @num: number to be converten in an string.
 * @str: buffer to save the number as string.
 * @base: base to convert number
 *
 * Return: Nothing.
 */
void _itoa(long num, char *str, int base)
{
	int ind = 0, inNeg = 0;
	long oko = num;
	char forms[] = {"0123456789abcdef"};

	if (oko == 0)
		str[ind++] = '0';

	if (str[0] == '-')
		inNeg = 1;

	while (oko)
	{
		if (oko < 0)
			str[ind++] = forms[-(oko % base)];
		else
			str[ind++] = forms[oko % base];
		oko /= base;
	}
	if (inNeg)
		str[ind++] = '-';

	str[ind] = '\0';
	_strrev(str);
}


/**
 * _atoi - convert a string to an integer.
 * @s: pointer to str to be converted.
 *
 * Return: int of string or 0.
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int num = 0;

	while (!('0' <= *s && *s <= '9') && *s != '\0')
	{
		if (*s == '-')
			sign *= -1;
		if (*s == '+')
			sign *= +1;
		s++;
	}

	while ('0' <= *s && *s <= '9' && *s != '\0')
	{

		num = (num * 10) + (*s - '0');
		s++;
	}
	return (num * sign);
}

/**
 * _countchars - counts the chars march in the string.
 * @str: pointer to string
 * @chars: string with  chars to be counted
 *
 * Return: int of string or 0.
 */
int _countchars(char *str, char *chars)
{
	int i = 0, count = 0;

	for (; str[i]; i++)
	{
		if (str[i] == chars[0])
			count++;
	}
	return (count);
}
