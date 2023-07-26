#include "shell.h"
#include <stdlib.h>

/**
 * **strtow - splits a string into words
 * @str: string input
 * @d: string delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)

{
	int g, h, o, r, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[g] != '\0'; g++)
		if (!is_delim(str[g], d) && (is_delim(str[g + 1], d) || !str[g + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (g = 0, h = 0; h < numwords; h++)
	{
		while (is_delim(str[g], d))
			g++;
		o = 0;
		while (!is_delim(str[g + o], d) && str[g + o])
			o++;
		s[h] = malloc((o + 1) * sizeof(char));
		if (!s[h])
		{
			for (o = 0; o < h; o++)
				free(s[o]);
			free(s);
			return (NULL);
		}
		for (r = 0; r < o; r++)
			s[h][r] = str[g++];
		s[h][r] = 0;
	}
	s[h] = NULL;
	return (s);
}

/**
 * **strtow2 - splits a string into words
 * @str: string input
 * @d: delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow2(char *str, char d)

{
	int g, h, o, r, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (g = 0; str[g] != '\0'; g++)
		if ((str[g] != d && str[g + 1] == d) ||
				    (str[g] != d && !str[g + 1]) || str[g + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (g = 0, h = 0; h < numwords; h++)
	{
		while (str[g] == d && str[g] != d)
			g++;
		o = 0;
		while (str[g + o] != d && str[g + o] && str[g + o] != d)
			o++;
		s[h] = malloc((o + 1) * sizeof(char));
		if (!s[h])
		{
			for (o = 0; o < h; o++)
				free(s[o]);
			free(s);
			return (NULL);
		}
		for (r = 0; r < o; r++)
			s[h][r] = str[g++];
		s[h][r] = 0;
	}
	s[h] = NULL;
	return (s);
}
