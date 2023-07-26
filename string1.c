#include "shell.h"

/**
 * _strcpy - string copied
 * @dest: destination
 * @src: source
 *
 * Return: destination pointer
 */

char *_strcpy(char *dest, char *src)

{
	int b = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[b] = src[b];
		b++;
	}
	dest[b] = 0;
	return (dest);
}

/**
 * _strdup - string duplicated
 * @str: duplicated string
 *
 * Return: string pointer duplicated
 */

char *_strdup(const char *str)

{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 * _puts - input string printed
 * @str: printed string
 *
 * Return: Nothing
 */

void _puts(char *str)

{
	int b = 0;

	if (!str)
		return;
	while (str[b] != '\0')
	{
		_putchar(str[b]);
		b++;
	}
}

/**
 * _putchar -character c stdout written
 * @c: printed character
 *
 * Return: On success 1
 * On error, -1 is returned, and errno is set appropriately
 */

int _putchar(char c)

{
	static int b;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || b >= WRITE_BUF_SIZE)
	{
		write(1, buf, b);
		b = 0;
	}
	if (c != BUF_FLUSH)
		buf[b++] = c;
	return (1);
}
