#include <stdlib.h>
#include "lists.h"

/**
 * get_nodeint_at_index - get node of a listint_t list at an index
 * @head: head of listint_t list
 * @index: index of a node at listint_t list
 *
 * Return: node at index, or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *node;
	unsigned int i;

	for (node = head, i = 0; i <= index && node; i++, node = node->next)
		if (i == index)
			return (node);
	return (NULL);
}
