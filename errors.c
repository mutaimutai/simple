#include "shell.h"

/**
 * _eputs - string input is printed
 * @str: printed string
 *
 * Return: Nothing
 */

void _eputs(char *str)

{
	int k = 0;

	if (!str)
		return;
	while (str[k] != '\0')
	{
		_eputchar(str[k]);
		k++;
	}
}

/**
 * _eputchar - character c written to stderr
 * @c: printed character
 *
 * Return: 1 on success
 * On error, return -1, and errno is set appropriately.
 */

int _eputchar(char c)

{
	static int k;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || k >= WRITE_BUF_SIZE)
	{
		write(2, buf, k);
		k = 0;
	}
	if (c != BUF_FLUSH)
		buf[k++] = c;
	return (1);
}

/**
 * _putfd - character c written to fd
 * @c: printed character
 * @fd: written file descriptor
 *
 * Return: On success 1
 * On error, return -1, and errno is set appropriately.
 */

int _putfd(char c, int fd)

{
	static int k;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || k >= WRITE_BUF_SIZE)
	{
		write(fd, buf, k);
		k = 0;
	}
	if (c != BUF_FLUSH)
		buf[k++] = c;
	return (1);
}

/**
 * _putsfd - string printed input
 * @str: printed string
 * @fd: written filedescriptor
 *
 * Return: chars number placed
 */

int _putsfd(char *str, int fd)

{
	int k = 0;

	if (!str)
		return (0);
	while (*str)
	{
		k += _putfd(*str++, fd);
	}
	return (k);
}
