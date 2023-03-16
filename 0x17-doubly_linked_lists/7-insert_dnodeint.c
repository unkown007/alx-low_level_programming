#include <stdlib.h>
#include "lists.h"
#include <stdio.h>

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
	unsigned int i = 0;

	new = NULL;
	if (idx == 0)
		new = add_dnodeint(h, n);
	else
	{
		node = *h;
		i = 1;
		if (node != NULL)
			while (node->prev != NULL)
				node = node->prev;
		while (node != NULL)
		{
			if (i == idx)
			{
				if (node->next == NULL)
					new = add_dnodeint_end(h, n);
				else
				{
					new = malloc(sizeof(dlistint_t));
					if (new != NULL)
					{
						new->n = n;
						new->next = node->next;
						new->prev = node;
						node->next->prev = new;
						node->next = new;
					}
				}
				break;
			}
			node = node->next;
			i++;
		}
	}

	return (new);
}
