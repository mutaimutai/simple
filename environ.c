#include "shell.h"

/**
 * _myenv - prints current environment
 * @info: structure having potential arguments
 * Return: Always 0
 */

int _myenv(info_t *info)

{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - gets value of environ variable
 * @info: structure having potentila argument
 * @name: env var name
 *
 * Return: value
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
 * _mysetenv - Initialize new environment variable,
 * or modify existing one
 * @info: structure having potential arguments
 * Return: Always 0
 */

int _mysetenv(info_t *info)

{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove environmental variable
 * @info: structure having potential arguments
 * Return: Always 0
 */

int _myunsetenv(info_t *info)

{
	int b;

	if (info->argc == 1)
	{
		_eputs("Too many arguments\n");
		return (1);
	}
	for (b = 1; b <= info->argc; b++)
		_unsetenv(info, info->argv[b]);
	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info: structure having potential arguments
 * Return: Always 0
 */

int populate_env_list(info_t *info)

{
	list_t *node = NULL;
	size_t b;

	for (b = 0; environ[b]; b++)
		add_node_end(&node, environ[b], 0);
	info->env = node;
	return (0);
}
