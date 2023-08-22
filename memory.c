#include "shell.h"

/**
* bfree - Frees a pointer and Nulls address
* @ptr: Address of pointer to free
*
* Return: If freed 1, otherwise 0.
*/
int bfree(void **ptr)
{
if (ptr && *ptr)
{
free(*ptr);
*ptr = NULL;
return (1);
}
return (0);
}
