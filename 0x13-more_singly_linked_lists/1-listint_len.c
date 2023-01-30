#include <stdlib.h>
#include "lists.h"

/**
 * listint_len - compute the number of elements in a linked listint_t list
 * @h: linked listint_t list
 *
 * Return: number of elements
 */
size_t listint_len(const listint_t *h)
{
	if (h == NULL)
		return (0);
	return (1 + listint_len(h->next));
}
