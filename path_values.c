#include "shell.h"
/**
 * path_value - gets each path from the mainPATH
 * @arg:input from user
 * @env:environment variable
 * Return:pointer to the path as string
 */
int path_value(char **arg, char **env)
{
	chatr *token = NULL, *path_content = NULL, *path_l =  NULL;
	size_t path_len, arg_len;
	struct stat stat_line_ptr;

	if (stat(*arg, &stat_lineptr) == 0)
		return (-1);
	path_content = path(env);
	if(!path_content)
		return (-1);
	token = strtok(path_content, ":");
	arg_len = strlen(*arg);
	while (token)
	{
		path_len = strlen(token);
		path_l = malloc(sizeof(char) * (path_len + arg_len + 2));
		if(!path)
		{
			free(path_content);
			return (-1);
		}
		path_l = strcpy(path_l, token);
		strcat(path_l, "/");
		strcat(path_l, *arg);
		if(stat(path_l, &stat_lineptr) == 0)
		{
			*arg = path_l;
			free(path_content);
			return (0);
		}
		free(path_l);
		token = strtok(NULL, ":");
	}
	token = '\0';
	free(path_content);
	return (-1);
}
