#include "shell.h"
#include <stdlib.h>

/**
 * **strtow - words split into string
 * @str: string input
 * @d: string delimeter
 * Return: string array pointer, failure on NULL
 */

char **strtow(char *str, char *d)

{
	int g, n, o, r, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (g = 0; str[g] != '\0'; g++)
		if (!is_delim(str[g], d) && (is_delim(str[g + 1], d) || !str[g + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (g = 0, n = 0; n < numwords; n++)
	{
		while (is_delim(str[g], d))
			g++;
		o = 0;
		while (!is_delim(str[g + o], d) && str[g + o])
			o++;
		s[n] = malloc((o + 1) * sizeof(char));
		if (!s[n])
		{
			for (o = 0; o < n; o++)
				free(s[o]);
			free(s);
			return (NULL);
		}
		for (r = 0; r < o; r++)
			s[n][r] = str[g++];
		s[n][r] = 0;
	}
	s[n] = NULL;
	return (s);
}

/**
 * **strtow2 - words gotten after splitting of string
 * @str: string input
 * @d: delimeter
 * Return: string array pointer, failure if NULL
 */

char **strtow2(char *str, char d)

{
	int g, n, o, r;
	char **words;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (g = 0; str[g] != '\0'; g++)
		if ((str[g] != d && str[g + 1] == d) ||
				(str[g] != d && !str[g + 1]) || str[g + 1] == d)
			numwords;
	word = malloc((numwords + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (g = 0, n = 0; n < numwords; n++)
	{
		while (str[g] == d && str[g] != d)
			g++;
		o = 0;
		while (str[g + o] != d && str[g + o] && str[g + o] != d)
			o++;
		s[n] = malloc((o + 1) * sizeof(char));
		if (!s[n])
		{
			for (o = 0; o < n; o++)
				free(s[o]);
			free(s);
			return (NULL);
		}
		for (r = 0; r < o; r++)
			s[n][r] = str[g++];
		s[n][r] = 0;
	}
	s[n] = NULL;
	return (s);
}
