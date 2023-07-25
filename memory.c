#include "shell.h"
#include <stdlib.h>

/**
 * bfree - pointer freed and addree NULL
 * @ptr: pointer address freed
 *
 * Return: 1 if freed, 0 otherwise
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
