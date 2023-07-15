#include "shell.h"

/**
 * _eputs - prints input string
 * @str: string to be printed
 *
 * Return: Nothing
 */

void _eputs(char *str)

{
	int w = 0;

	if (!str)
		return;
	while (str[w] != '\0')
	{
		_eputchar(str[w]);
		w++;
	}
}

/**
 * _eputchar - writes character c to stderr
 * @c: character to print
 * Return: 1 on success
 * On error, -1 is returned, and errno is set appropriately
 */

int _eputchar(char c)

{
	static int w;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || w >= WRITE_BUF_SIZE)
	{
		write(2, buf, w);
		w = 0;
	}
	if (c != BUF_FLUSH)
	buf[w++] = c;
	return (1);
}

/**
 * _putfd - writes character c to given fd
 * @c: character to print
 * @fd: filedescriptor to write to
 *
 * Return: 1 on success
 * On error, -1 is returned, and errno is set appropriately
 */

int _putfd(char c, int fd)

{
	static int w;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || w >= WRITE_BUF_SIZE)
	{
		write(fd, buf, w);
			w = 0;
	}
	if (c != BUF_FLUSH)
		buf[w++] = c;
	return (1);
}

/**
 * _putsfd - prints input string
 * @str: string to be printed
 * @fd: filedescriptor to write to
 *
 * Return: number of chars put
 */

int _putsfd(char *str, int fd)

{
	int w = 0;

	if (!str)
		return (0);
	while (*str)
	{
		w += _putfd(*str++, fd);
	}
	return (w);
}
