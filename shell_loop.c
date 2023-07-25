#include "shell.h"
#include <stdlib.h>

/**
 * hsh - main shell loop
 * @info: info struct & parameter struct
 * @av: main() vector argument
 *
 * Return: Success on 0, on error 1, or code error
 */

int hsh(info_t *info, char **av)

{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (r != -1 && builtin_ret != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		r = get_input(info);
		if (r != -1)
		{
			set_info(info, av);
			builtin_ret = find_builtin(info);
			if (builtin_ret == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_ret);
}

/**
 * find_builtin - builtin command found
 * @info: return info struct & parameter
 *
 * Return: -1 if builtin not found
 * if executed successfully 0
 */

int find_builtin(info_t *info)

{
	int z, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (z = 0; builtintbl[z].type; z++)
		if (_strcmp(info->argv[0], builtintbl[z].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintbl[z].func(info);
			break;
		}
	return (built_in_ret);
}

/**
 * find_cmd - command found in PATH
 * @info: info return struct & parameter
 *
 * Return: void
 */

void find_cmd(info_t *info)

{
	char *path = NULL;
	int z, y;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}

	for (z = 0, y = 0; info->arg[z]; z++)
		if (!is_delim(info->arg[z], "\t\n"))
			y++;
	if (!y)
		return;

	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
					|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}

/**
 * fork_cmd - forks cmd to run an executable thread
 * @info: info & parameter return struct
 *
 * Return: void
 */

void fork_cmd(info_t *info)

{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}
