#include "shell.h"

/**
 * is_cmd - determines if a file is an executable command
 * @info: struct info
 * @path: file path
 *
 * Return: True 1, 0 otherwise
 */

int is_cmd(info_t *info, char *path)

{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - characters duplicated
 * @pathstr: string PATH
 * @start: index started
 * @stop: index stopped
 *
 * Return: buffer new pointer
 */

char *dup_chars(char *pathstr, int start, int stop)

{
	static char buf[1024];
	int e = 0, c = 0;

	for (c = 0, e = start; e < stop; e++)
		if (pathstr[e] != ':')
			buf[c++] = pathstr[e];
	buf[c] = 0;
	return (buf);
}

/**
 * find_path - finds this cmd in the PATH string
 * @info: struct info
 * @pathstr: string PATH
 * @cmd: find cmd
 *
 * Return: full path of cmd if found or NULL
 */

char *find_path(info_t *info, char *pathstr, char *cmd)

{
	int e = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[e] || pathstr[e] == ':')
		{
			path = dup_chars(pathstr, curr_pos, e);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[e])
				break;
			curr_pos = e;
		}
		e++;
	}
	return (NULL);
}
