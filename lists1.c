#include "shell.h"

/**
 * list_len - determines length of linked list
 * @h: node 1 pointer
 *
 * Return: list size
 */

size_t list_len(const list_t *h)

{
	size_t t = 0;

	while (h)
	{
		h = h->next;
		t++;
	}
	return (t);
}

/**
 * list_to_strings - returns an array of strings of the list->str
 * @head: node 1 pointer
 *
 * Return: string array
 */

char **list_to_strings(list_t *head)

{
	list_t *node = head;
	size_t t = list_len(head), s;
	char **strs;
	char *str;

	if (!head || !t)
		return (NULL);
	strs = malloc(sizeof(char *) * (t + 1));
	if (!strs)
		return (NULL);
	for (t = 0; node; node = node->next, t++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (s = 0; j < t; s++)
				free(strs[s]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[t] = str;
	}
	strs[t] = NULL;
	return (strs);
}


/**
 * print_list - prints all elements of a list_t linked list
 * @h: node 1 pointer
 *
 * Return: list size
 */

size_t print_list(const list_t *h)
{
	size_t t = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		t++;
	}
	return (i);
}

/**
 * node_starts_with - returns node whose string starts with prefix
 * @node: head list pointer
 * @prefix: match string
 * @c: the next character after prefix to match
 *
 * Return: match node or null
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
 * get_node_index - gets the index of a node
 * @head: head list pointer
 * @node: node pointer
 *
 * Return: index of node or -1
 */

ssize_t get_node_index(list_t *head, list_t *node)

{
	size_t t = 0;

	while (head)
	{
		if (head == node)
			return (t);
		head = head->next;
		t++;
	}
	return (-1);
}
