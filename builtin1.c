#include "shell.h"

/**
 * _myhistory-previously used commands
 * @info:arguments fro a structure
 *
 *  Return: Always 0
 */

int _myhistory(info_t *info)

{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias-what is from alias
 * @info:parameter frm struct
 * @str:string alias
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
 * set_alias-alias string
 * @info:parameter from struct
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
 * print_alias-a function that prints an alias
 * @node:alias node
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
 * _myalias - builtin alias (man alias)
 * @info:potential arguments from structure
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
