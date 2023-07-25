#include "shell.h"
#include <stdlib.h>

/**
 * is_chain - cureent char test in buffer delimeter chain
 * @info: struct parameter
 * @buf: char buffer
 * @p: current buf position address
 *
 * Return: address of buf position
 */

int is_chain(info_t *info, char *buf, size_t *p)

{
	size_t t = *p;

	if (buf[t] == '|' && buf[t + 1] == '|')
	{
		buf[t] = 0;
		t++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[t] == '&' && buf[t + 1] == '&')
	{
		buf[t] = 0;
		t++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[t] == ';')
	{
		buf[t] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = t;
	return (1);
}

/**
 * check_chain - checks we should continue chaining based o last status
 * @info: struct parameter
 * @buf: buffer char
 * @p: address of current position buf
 * @i: starting positon buf
 * @len: buf length
 *
 * Return: void
 */

void check_chain(info_t *info, char *buf, size_t *p, size_t s, size_t len)

{
	size_t t = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[s] = 0;
			t = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[s] = 0;
			t = len;
		}
	}

	*p = t;
}

/**
 * replace_alias - aliases of string token replaced
 * @info: struct parameter
 *
 * Return: 1 if replaced , otherwise 0
 */

int replace_alias(info_t *info)

{
	int s;
	list_t *node;
	char *p;

	for (s = 0; s < 10; s++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars - tokenized string in vars replaced
 * @info: struct parameter
 *
 * Return: 1 if replaced , otherwise 0
 */

int replace_vars(info_t *info)

{
	int s = 0;
	list_t *node;

	for (s = 0; info->argv[s]; s++)
	{
		if (info->argv[s][0] != '$' || !info->argv[s][1])
			continue;
		if (!_strcmp(info->argv[s], "$?"))
		{
			replace_strings(&(info->argv[s]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[s], "$$"))
		{
			replace_strings(&(info->argv[s]),
					_strdup(convert_number(getpid(), 10, 0)));
				continue;
		}
		node = node_starts_with(info->env, &info->argv[s][1], '=');
		if (node)
		{
			replace_strings(&(info->argv[s]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_strings(&info->argv[s], _strdup(" "));
	}
	return (0);
}

/**
 * replace_strings -string replaced
 * @old: old string address
 * @new: new string
 *
 * Return: 1 if replaced, otherwise 0
 */

int replace_strings(char **old, char *new)

{
	free(*old);
	*old = new;
	return (1);
}
