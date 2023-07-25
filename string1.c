#include "shell.h"
#include <stdlib.h>

/**
 * _strcpy - string copied
 * @dest: destination
 * @src: source
 *
 * Return: destination pointer
 */

char *_strcpy(char *dest, char *src)

{
	int u = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[u])
	{
		dest[u] = src[u];
		u++;
	}
	dest[u] = 0;
	return (dest);
}

/**
 * _strdup - string duplicate
 * @str: duplicate string
 *
 * Return: duplicate string pointer
 */

char *_strdup(const char *str)

{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str)
		length++;
	ret = malloc(sizeof(char) * (length + 1));

	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *str;
	return (ret);
}

/**
 * _puts - string input printed
 * @str: printed string
 *
 * Return: Nothing
 */

void _puts(char *str)

{
	int u = 0;

	if (!str)
		return;
	while (str[u] != '\0')
	{
		_putchar(str[u]);
		u++;
	}
}

/**
 * _putchar - writes character c to stdout
 * @c: print character
 *
 * Return: 1 on success,
 * on error, return -1, and errno is appropriately set
 */

int _putchar(char c)

{
	static int u;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || u >= WRITE_BUF_SIZE)
	{
		write(1, buf, u);
		u = 0;
	}
	if (c != BUF_FLUSH)
		buf[u++] = c;
	return (1);
}
