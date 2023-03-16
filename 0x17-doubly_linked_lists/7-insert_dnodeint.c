#include <stdlib.h>
#include "lists.h"
#include <stdio.h>

/**
 * list_size -  computes list size
 * @h: head
 *
 * Return: size
 */
unsigned int list_size(dlistint_t *h)
{
	if (h == NULL)
		return (0);
	return (1 + list_size(h->next));
}

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: head of a dlistint_t linked list
 * @idx: position to insert
 * @n: integer element to insert
 *
 * Return: address of the new node, or NULL
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *node;
	dlistint_t *new;
	unsigned int i = 0, size;

	size = list_size(*h);
	if (*h == NULL || idx >= size)
		return (NULL);
	if (idx == 0)
		return (add_dnodeint(h, n));
	if (idx == size - 1)
		return (add_dnodeint_end(h, n));
	node = *h;
	while (node && i < idx)
	{
		node = node->next;
		i++;
	}
	if (i == idx)
	{
		new =  malloc(sizeof(dlistint_t));
		if (new == NULL)
			return (NULL);
		new->n = n;
		new->next = node;
		new->prev = node->prev;
		node->prev->next = new;
		return (new);
	}
	return (NULL);
}
