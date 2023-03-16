#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_dlistint - prints all the elements of a dlistint_t list
 * @h: head of a dlistint_t doubly linked list
 *
 * Return: number of the nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	if (h == NULL)
		return (0);
	fprintf(stdout, "%d\n", h->n);
	return (1 + print_dlistint(h->next));
}
