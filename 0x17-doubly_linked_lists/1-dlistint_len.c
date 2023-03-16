#include <stdlib.h>
#include "lists.h"

/**
 * dlistint_len - computes the number of elements in a linked dlistint_t list
 * @h: head of a linked dlistint_t list
 *
 * Return: number of elements in a linked dlistint list
 */
size_t dlistint_len(const dlistint_t *h)
{
	if (h == NULL)
		return (0);
	return (1 + dlistint_len(h->next));
}
