#include "shell.h"

/**
 * _strlen - string length returned
 * @s: string length to check
 *
 * Return: string length integer
 */

int _strlen(char *s)

{
	int v = 0;

	if (!s)
		return (0);

	while (*s++)
		v++;
	return (v);
}

/**
 * _strcmp - string comparison by doing lexographicing
 * @s1: string 1
 * @s2: string 2
 *
 * Return: s1 < s2 negative, s1 > s2 positive, s1 == s2 zero
 */

int _strcmp(char *s1, char *s2)

{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - needle checks beginning with haystack
 * @haystack: search string
 * @needle: find substring
 *
 * Return: next char address in haystack or NULL
 */

char *starts_with(const char *haystack, const char *needle)

{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - 2 strings concatenated
 * @dest: buffer destination
 * @src: buffer source
 *
 * Return: buffer destination pointer
 */

char *_strcat(char *dest, char *src)

{
	char *ret = dest;

	while (dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
