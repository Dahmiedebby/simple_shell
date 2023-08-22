#include "shell.h"

/**
* _eputs - prints input string
* @str: The string be print
*
* Return: Nothing
*/
void _eputs(char *str)
{
int i = 0;
if (!str)
return;
while (str[i] != '\0')
{
_eputchar(str[i]);
i++;
}
}

/**
* _eputchar - Writes character c to stderr
* @c: The character to be printed
*
* Return: 1. on success
* On error, -1 is returned, and appropriately set errno.
*/
int _eputchar(char c)
{
static int i;
static char buf[WRITE_BUF_SIZE];
if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(2, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}

/**
* _putfd - Writes character c to given fd
* @c: Character to print
* @fd: the filedescriptor to write to
*
* Return: 1. on success 
* On error, -1 is returned, and appropriately set errno.
*/
int _putfd(char c, int fd)
{
static int i;
static char buf[WRITE_BUF_SIZE];
if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(fd, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}

/**
* _putsfd - Prints input string
* @str: String to be printed
* @fd: The Filedescriptor to write to
*
* Return: The number of chars put
*/
int _putsfd(char *str, int fd)
{
int i = 0;
if (!str)
return (0);
while (*str)
{
i += _putfd(*str++, fd);
}
return (i);
}

