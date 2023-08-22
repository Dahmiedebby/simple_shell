
#include "shell.h"

/**
**_strncpy - Copies a String
*@dest: The destination string been copied to
*@src: The source string
*@n: The amount of characters been copied
*Return: The concatenated string
*/
char *_strncpy(char *dest, char *src, int n)
{
int i, j;
char *s = dest;
i = 0;
while (src[i] != '\0' && i < n - 1)
{
dest[i] = src[i];
i++;
}
if (i < n)
{
j = i;
while (j < n)
{
dest[j] = '\0';
j++;
}
}
return (s);
}

/**
**_strncat - Concatenates two strings
*@dest: The first string
*@src: The second string
*@n: The amount of bytes been maximally used
*Return: The concatenated string
*/
char *_strncat(char *dest, char *src, int n)
{
int i, j;
char *s = dest;
i = 0;
j = 0;
while (dest[i] != '\0')
i++;
while (src[j] != '\0' && j < n)
{
dest[i] = src[j];
i++;
j++;
}
if (j < n)
dest[i] = '\0';
return (s);
}

/**
**_strchr - Locates a character in a string
*@s: String to be parsed
*@c: Character to be looked for
*Return: (s) A pointer to the memory area s
*/
char *_strchr(char *s, char c)
{
do {
if (*s == c)
return (s);
} while (*s++ != '\0');
return (NULL);
}
