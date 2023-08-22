#include "shell.h"

/**
* interactive - If shell is in interactive mode returns true
* @info: Struct address
*
* Return: if interactive mode is 1, otherwise 0
*/
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
* is_delim - Checks if delimeter is a character
* @c: the char to be checked
* @delim: The delimeter string
* Return: if true 1, if false 0
*/
int is_delim(char c, char *delim)
{
while (*delim)
if (*delim++ == c)
return (1);
return (0);
}

/**
* _isalpha - Checks for alphabetic character
* @c: Character to be inputed
* Return: if c is alphabetic 1, otherwise 0
*/

int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}

/**
* _atoi - Converts string to an integer
* @s: The string to convert
* Return: if no numbers in string 0, converted number otherwise
*/

int _atoi(char *s)
{
int i, sign = 1, flag = 0, output;
unsigned int result = 0;
for (i = 0; s[i] != '\0' && flag != 2; i++)
{
if (s[i] == '-')
sign *= -1;
if (s[i] >= '0' && s[i] <= '9')
{
flag = 1;
result *= 10;
result += (s[i] - '0');
}
else if (flag == 1)
flag = 2;
}
if (sign == -1)
output = -result;
else
output = result;
return (output);
}

