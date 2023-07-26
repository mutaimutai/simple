#include "shell.h"

/**
 * _memset - fills memory with a constant byte
 * @s: area memory pointer
 * @b: the byte to fill *s with
 * @n: bytes amount filled
 * Return: (s) a pointer to the memory area s
 */

char *_memset(char *s, char b, unsigned int n)

{
	unsigned int u;

	for (u = 0; u < n; u++)
		s[u] = b;
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
		free(*pp++);
	free(a);
}

/**
 * _realloc - memory block reallocated
 * @ptr: pointer to previous malloc'ated block
 * @old_size: previous block byte size
 * @new_size: new block size byte
 *
 * Return: pointer to da ol'block nameen.
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
