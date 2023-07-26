#include "shell.h"
int execute_exit(char **args);
int execute_ctrld(char **args);

char *builtin_str[] = {"exit", "^D"};

/**
 * builtin_str-list of corresponding functions
 */

int (*builtin_func[])(char **) = {&execute_exit, &execute_ctrld};

/**
 * num_builtins - Returns the number of bult-in commands.
 * Return:Number of bulit-in commands
 */

int num_builtins(void)

{
	return (sizeof(builtin_str) / sizeof(char *));
}

/**
 * execute_exit - built-in function to exit the shell
 * @args: list of arguments
 * Return: terminate execution
 */

int execute_exit(char **args)

{
	(void)args;
	free(args);
	return (200);
}

/**
 * execute_ctrld - built-in handle control D("^D") call
 * @args:lists of arguments
 * Return:terminate execution
 */

int execute_ctrld(char **args)

{
	(void)args;
	free(args);
	return (200);
}

/**
 * execute_builtin - execute built-in commands
 * @args: list of arguments representing the command and its value/path
 * Return: 1 if built-in command executed successfully, 0 otherwise
 */

int execute_builtin(char **args)

{
	if (args[0] == NULL)
	{
		fprintf(stderr, "shell: expected arguent to command\n");
		return (0);
	}

	for (int i = 0; i < num_builtins(); i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
			return (builtin_func[i](args));
	}
	return (0);
}

/**
 * fork_func - fork and execute external commands
 * @arg: command and values path
 * @av: name of our program
 * @env: environment variable
 * @lineptr: command line for the user
 * @np: process ID
 * @c: checker and new test.
 * Return: 0 on success
 */

int fork_func(char **arg, char **av, char **env, char *lineptr, int np, int c)

{
	pid_t child;
	int status;
	char *format = "%s: %d: %s: not found\n";

	if (arg[0] == NULL)
		return (0);
	status = execute_builtin(arg);
	if (status != 0)
		return (status);
	child = fork();
	if (child == 0)
	{
		if (execve(arg[0], arg, env) == -1)
		{
			fprintf(stderr, format, av[0], np, arg[0]);
			if (!c)
				free(arg[0]);
			free(arg);
			free(lineptr);
			exit(errno);
		}
	}
	else
	{
		wait(&status);
		return (status);
	}
	return (0);
}
