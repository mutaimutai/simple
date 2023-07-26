#include "shell.h"

/**
 * _myhistory - history list is displayed
 * @info: Structure containing having arguments
 *
 *  Return: Always 0
 */

int _myhistory(info_t *info)

{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - string gotten from alias
 * @info: struct parameter
 * @str: alias string
 *
 * Return: On success 0 always, error 1
 */

int unset_alias(info_t *info, char *str)

{
	char *p, e;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	e = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = e;
	return (ret);
}

/**
 * set_alias - string alias
 * @info: struct for parameter
 * @str: alias string
 *
 * Return: 0 on success always, 1 on error
 */

int set_alias(info_t *info, char *str)

{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - builtin alias mimmiced (man alias)
 * @info: Structure having potential arguments
 *
 *  Return: Always 0
 */

int _myalias(info_t *info)

{
	int f = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (f = 1; info->argv[f]; f++)
	{
		p = _strchr(info->argv[f], '=');
		if (p)
			set_alias(info, info->argv[f]);
		else
			print_alias(node_starts_with(info->alias, info->argv[f], '='));
	}

	return (0);
}
