#include "shell.h"

/**
 * _myenv-prints environment variables
 * @info:arguments from struct
 *
 * Return: Always 0
 */

int _myenv(info_t *info)

{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv-getting environment variables values
 * @info:arguments
 * @name: environment var name
 *
 * Return: the value
 */

char *_getenv(info_t *info, const char *name)

{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv-setting a new environment variable
 * @info: Structure having potential arguments
 *
 *  Return: Always 0
 */

int _mysetenv(info_t *info)

{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - environment variable removed
 * @info: Structure having potential arguments
 *
 * Return: Always 0
 */

int _myunsetenv(info_t *info)

{
	int h;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (h = 1; h <= info->argc; h++)
		_unsetenv(info, info->argv[h]);

	return (0);
}

/**
 * populate_env_list - env linked list
 * @info:arguments
 *
 * Return: Always 0
 */

int populate_env_list(info_t *info)

{
	list_t *node = NULL;
	size_t h;

	for (h = 0; environ[h]; h++)
		add_node_end(&node, environ[h], 0);
	info->env = node;
	return (0);
}
