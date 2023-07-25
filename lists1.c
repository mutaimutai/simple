#include "shell.h"
#include <stdlib.h>

/**
 * list_len - length of list link is determined
 * @h: first node pointer
 *
 * Return: list size
 */

size_t list_len(const list_t *h)

{
	size_t a = 0;

	while (h)
	{
		h = h->next;
		a++;
	}
	return (a);
}

/**
 * list_to_strings -string array returned to list->str
 * @head: node 1 pointer
 *
 * Return: string array
 */

char **list_to_strings(list_t *head)

{
	list_t *node = head;
	size_t a = list_len(head), b;
	char **strs;
	char *str;

	if (!head || !a)
		return (NULL);
	strs = malloc(sizeof(char *) * (a + 1));
	if (!strs)
		return (NULL);
	for (a = 0; node; node = node->next, a++)
	{
		strs = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (b = 0; b < a; b++)
				free(strs[b]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[a] = str;
	}
	strs[a] = NULL;
	return (strs);
}

/**
 * print_list - prints all elemnts of a linked list
 * @h: 1 node pointer
 *
 * Return: list size
 */

size_t print_list(const list_t *h)

{
	size_t a = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		a++;
	}
	return (a);
}

/**
 * node_starts_with - returns nodes beginning with prefixes
 * @node: list head pointer
 * @prefix: match string
 * @c: prefix to match next character
 *
 * Return: node match or null
 */

list_t *node_starts_with(list_t *node, char *prefix, char c)

{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - node index gotten
 * @head: list head pointer
 * @node: node pointer
 *
 * Return: index of node -1
 */

ssize_t get_node_index(list_t *head, list_t *node)

{
	size_t a = 0;

	while (head)
	{
		if (head == node)
			return (a);
		head = head->next;
		a++;
	}
	return (-1);
}
