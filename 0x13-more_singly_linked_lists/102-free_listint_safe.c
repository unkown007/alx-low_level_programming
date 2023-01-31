#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * free_listint_safe - frees a listint_t linked list
 * @h: head of a listint_t linked list
 *
 * Return: size of the list that was free'd
 */
size_t free_listint_safe(listint_t **h)
{
	size_t i, size = 0;
	const listint_t **addr = NULL;
	listint_t *tmp;

	if  (*h == NULL)
		return (0);
	while (*h)
	{
		for (i = 0; i < size; i++)
		{
			if (*h == addr[i])
			{
				free(addr);
				*h = NULL;
				return (size);
			}
		}
		size++;
		addr = add_address(addr, size, *h);
		tmp = *h;
		*h = (*h)->next;
		free(tmp);
	}
	free(addr);
	*h = NULL;
	return (size);
}
