#include "shell.h"
#include <stdlib.h>

/**
 * _memset - memory filled with byte constant
 * @s: memory pinter to are
 * @b: byte to fill *s with
 * @n: amount of bytes to be filled
 * Return: (s) pointer to memory area s
 */

char *_memset(char *s, char b, unsigned int n)

{
	unsigned int d;

	for (d = 0; d < n; d++)
		s[d] = b;
	return (s);
}

/**
 * ffree - frees a string of strings
 * @pp: string of strings
 */

void ffree(char **pp)

{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
	{
		free(*pp);
		pp++;
	}
	free(a);
}

/**
 * _realloc - blocks of memory allocated
 * @ptr: previous malloc'ated block pointer
 * @old_size: previous block byte size
 * @new_size: new block byte size
 *
 * Return: pointer to da ol'block nammen
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)

{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);
	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
