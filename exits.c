#include "shell.h"

/**
 * *_strncpy - copies string
 * @dest: destination string to be copied to
 * @src: source string
 * @n: amount of characters to be copied to
 * Return: concatenated string
 */

char *_strncpy(char *dest, char *src, int n)

{
	int u, v;
	char *s = dest;

	u = 0;
	while (src[u] != '\0' && u < n - 1)
	{
		dest[u] = src[u];
		u++;
	}
	if (u < n)
	{
		v = u;
		while (v < n)
		{
			dest[v] = '\0';
			v++;
		}
	}
	return (s);
}

/**
 * *_strncat - concatenate 2 strings
 * @dest: string 1
 * @src: string 2
 * @n: amount of bytes to be maximally used
 * Return: concatenated string
 */

char *_strncat(char *dest, char *src, int n)

{
	int u, v;
	char *s = dest;

	u = 0;
	v = 0;
	while (dest[u] != '\0')
		u++;
	while (src[v] != '\0' && v < n)
	{
		dest[u] = src[v];
		u++;
		v++;
	}
	if (v < n)
		dest[u] = '\0';
	return (s);
}

/**
 * *_strchr - locates character in string
 * @s: string to parsed
 * @c: character to look for
 * Return: (s) pointer to memory area s
 */

char *_strchr(char *s, char c)

{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
