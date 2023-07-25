#include "shell.h"
#include <stdlib.h>

/**
 * input_buf - buffer chained commands
 * @info: parameter struct
 * @buf: address buffer
 * @len: address of len var
 *
 * Return: bytes read
 */

ssize_t input_buf(info_t *info, char **buf, size_t *len)

{
	ssize_t z = 0;
	ssize_t len_p = 0;


	if (!*len)
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		z = getline(buf, &len_p, stdin);
#else
		z = _getline(info, buf, (size_t *)&len_p);
#endif
		if (z > 0)
		{
			if ((*buf)[z - 1] == '\n')
			{
				(*buf)[z - 1] = '\0';
				z--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			/* if(_strchr(*buf, ';')) is this a command chain? */
			{
				*len = z;
				info->cmd_buf = buf;
			}
		}
	}
	return (z);
}

/**
 * get_input - gets line minus newline
 * @info: parameter struct
 *
 * Return: bytes read
 */

ssize_t get_input(info_t *info)

{
	static char *buf;
	static size_t f, g, len;
	ssize_t z = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	z = input_buf(info, &buf, &len);
	if (z == -1)
		return (-1);
	if (len)
	{
		g = f;
		p = buf + f;

		check_chain(info, buf, &g, f, len);
		while (g < len)
		{
			if (is_chain(info, buf, &g))
				break;
			g++;
		}

		f = g + 1;
		if (f >= len)
		{
			f = len = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p;
		return (_strlen(p));
	}

	*buf_p = buf;
	return (z);
}

/**
 * read_buf - reads buffer
 * @info: parameter struct
 * @buf: buffer
 * @i: size
 * Return: z
 */

ssize_t read_buf(info_t *info, char *buf, size_t *i)

{
	ssize_t z = 0;

	if (*i)
		return (0);
	z = read(info->readfd, buf, READ_BUF_SIZE);
	if (z >= 0)
		*i = z;
	return (z);
}

/**
 * _getline - gets next line input from STDIN
 * @info: parameter struct
 * @ptr: address pointer to buffer, preallocated or NULL
 * @length: size preallocated ptr buffer if not NULL
 *
 * Return: s
 */
int _getline(info_t *info, char **ptr, size_t *length)

{
	static char buf[READ_BUF_SIZE];
	static size_t f, len;
	size_t l;
	ssize_t z = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (f == len)
		f = len = 0;
	z = read_buf(info, buf, &len);
	if (z == -1 || (z == 0 && len == 0))
		return (-1);
	c = _strchr(buf + f, '\n');
	l = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + l : l + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buf + f, l - f);
	else
		_strncpy(new_p, buf + f, l - f + 1);
	s += l - f;
	f = l;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}

/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: signal number
 *
 * Return: void
 */

void sigintHandler(__attribute__((unused))int sig_num)

{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
