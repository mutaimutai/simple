#include "shell.h"

/**
 **_strncpy - string copied
 *@dest: string destination copied
 *@src: string source
 *@n: copied character amount
 *Return: string concatenated
 */

char *_strncpy(char *dest, char *src, int n)

{
	int y, z;
	char *s = dest;

	y = 0;
	while (src[y] != '\0' && y < n - 1)
	{
		dest[y] = src[y];
		y++;
	}
	if (y < n)
	{
		z = y;
		while (z < n)
		{
			dest[z] = '\0';
			z++;
		}
	}
	return (s);
}

/**
 **_strncat - string concatenated
 *@dest: string 1
 *@src: string 2
 *@n: the amount of bytes to be maximally used
 *Return: string concatenated
 */

char *_strncat(char *dest, char *src, int n)

{
	int y, z;
	char *s = dest;

	y = 0;
	z = 0;
	while (dest[y] != '\0')
		y++;
	while (src[z] != '\0' && z < n)
	{
		dest[y] = src[z];
		y++;
		z++;
	}
	if (z < n)
		dest[y] = '\0';
	return (s);
}

/**
 **_strchr - string character located
 *@s: parsed string
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
