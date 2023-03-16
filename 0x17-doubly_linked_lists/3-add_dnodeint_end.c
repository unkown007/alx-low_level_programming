#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: head of a linked dlistint_t list
 * @n: integer element to add
 *
 * Return: address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *node;

	node = *head;
	if (node != NULL)
		while (node->next != NULL)
			node = node->next;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	new->prev = node;
	if (node != NULL)
		node->next = new;
	else
		*head = new;
	return (new);
}
