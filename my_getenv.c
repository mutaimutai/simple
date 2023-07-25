#include "shell.h"
/**
 * my_getenv-is a function that prints out environment variable
 * @env:The environment variable to be printed
 */
void my_getenv(char **env)
{
	size_t n = 0;

	while (env[n])
	{
		frintf(stdout, "%s\n", env[n]);
		n++;
	}
}
