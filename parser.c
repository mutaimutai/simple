#include "shell.h"

/**
 * is_cmd - file is determined if in executable command
 * @info: struct info
 * @path: file path
 *
 * Return: 1 if true, otherwise 0
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
 * dup_chars - characters to be duplicated
 * @pathstr: string PATH
 * @start: index starting
 * @stop: index to stop
 *
 * Return: new buffer pointer
 */

char *dup_chars(char *pathstr, int start, int stop)

{
	static char buf[1024];
	int c = 0, e = 0;

	for (e = 0, c = start; c < stop; c++)
		if (pathstr[c] != ':')
			buf[e++] = pathstr[e];
	buf[e] = 0;
	return (buf);
}

/**
 * find_path - cmd found in string PATH
 * @info: struct info
 * @pathstr: string PATH
 * @cmd: cmd to find
 *
 * Return: cmd full path if found or NULL
 */

char *find_path(info_t *info, char *pathstr, char *cmd)

{
	int c = 0, curr_pos = 0;
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
		if (!pathstr[c] || pathstr[c] == ':')
		{
			path = dup_chars(pathstr, curr_pos, c);
			if (!path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[c])
				break;
			curr_pos = c;
		}
		c++;
	}
	return (NULL);
}
