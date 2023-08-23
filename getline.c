#include "main.h"



/**
* findchar - Find a specific character
* @s: string
* @c: char
* @len: lenght
* Return: 0 success or uint
*/

int findchar(char *s, char c, int *len)
{
	int i, find = 0, lenght = 0;

	lenght = _strlen(s);
	for (i = 0; i < lenght; i++)
		if (*(s + i) == c)
		{
			find = 1;
			*len = i + 1;
			break;
		}
	return (find);
}
/**
* _strcat_interne -  concatenate
* Description: The program's description _strcat
* @dest: 1 param
* @src: 2 param
* Return: Always 0 (Success)
*/

char *_strcat_interne(char *dest, char *src)
{
	int i = 0, len_dest, len_src;
	char *tmpstr = NULL, *destr = NULL;

	tmpstr = _strdup(dest);
	len_dest = _strlen(tmpstr);
	len_src = _strlen(src);
	destr = malloc(len_dest + len_src + 1);
	if (tmpstr)
		while (*(tmpstr + i) != '\0')
		{
			*(destr + i) = *(tmpstr + i);
			i++;
		}
	i = 0;
	if (src)
		while (*(src + i) != '\0')
		{
			*(destr + (len_dest + i)) = *(src + i);
			i++;
		}
	*(destr + (len_dest + len_src)) = '\0';
	free(tmpstr);
	return (destr);
}

/**
 * free_str - Free_str free allocated string
 * @str: second parameter
 * @tmp: Temporary string
 * @tmp_str: Temporary string
 * Return: always void
 **/


void free_str(char *str, char *tmp, char *tmp_str)
{
	if (str)
		free(str);
	if (tmp)
		free(tmp);
	if (tmp_str)
		free(tmp_str);
}


/**
 * _readline - _readline auxilary function
 * @line: Line
 * @buffer_size: buffer size
 * @fd: File descriptor
 * Return: always void
 **/
char *_readline(char **line, size_t *buffer_size, int fd)
{
	static size_t numberchar;
	int len = -1;
	char *str = NULL, *tmp_str = NULL, *tmp = NULL;

	str = malloc(*buffer_size * sizeof(char) + 1);
	if (!str)
		return (NULL);
	numberchar = 0;
	numberchar = read(fd, str, *buffer_size);
	str[numberchar] = '\0';
	if (findchar(str, '\n', &len))
	{
		tmp = _strncpy(tmp, str, len);
		tmp_str = _strcat_interne(tmp_str, tmp);
		*line = _strdup(tmp_str);
		free_str(str, tmp, tmp_str);
		return (*line);
	}
	if (numberchar == 1)
	{
		*line = str;
		free(str);
		return (*line);
	}
	while (numberchar > 0)
	{
		str[numberchar] = '\0';
		if (findchar(str, '\n', &len))
		{
			tmp = _strncpy(tmp, str, len);
			tmp_str = _strcat_interne(tmp_str, tmp);
			break;
		}
		tmp_str = _strcat_interne(tmp_str, str);
		numberchar = read(fd, str, *buffer_size);
	}
	*line = _strdup(tmp_str);
	free_str(str, tmp, tmp_str);
	return (*line);
}


/**
 * _getline - Write error
 * @line: second parameter
 * @buffer_size: buffer size
 * @fd: File descriptor
 * Return: always void
 **/

size_t _getline(char **line, size_t *buffer_size, size_t fd)
{
	size_t tmp_buffer_size;


	if (*buffer_size == 0)
	{
		tmp_buffer_size = 1024;
	}
	else
		tmp_buffer_size = *buffer_size;
	*line = _readline(line, &tmp_buffer_size, fd);
	*buffer_size = _strlen(*line);
	if (*buffer_size <= 0)
		return (-1);
	return (*buffer_size);
}
