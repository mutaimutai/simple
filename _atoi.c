#include "shell.h"

/**
 * interactive - if shell mode interactive return true
 * @info: address struct
 *
 * Return: interactive mode 1, otherwise 0
 */

int interactive(info_t *info)

{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - delimeter character
 * @c: checked char
 * @delim: string for delimeter
 * Return:true if 1, false if 0
 */

int is_delim(char c, char *delim)

{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - character for alphabetic order is checked
 * @c: input for character
 * Return: alphabetic if c is 1, otherwise 0
 */

int _isalpha(int c)

{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - integer is gotten after been converted fron string
 * @s: converted string
 * Return: 0 if no numbers in string, otherwise number converted
 */

int _atoi(char *s)

{
	int o, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (o = 0; s[o] != '\0' && flag != 2; o++)
	{
		if (s[o] == '-')
			sign *= -1;

		if (s[o] >= '0' && s[o] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[o] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
