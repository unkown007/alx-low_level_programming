#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint - adds a new node at the end of a dlistint_t list
 * @head: head of a linked dlistint_t list
 * @n: integer element to add
 *
 * Return: address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *node;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
	}
	else
	{
		node = *head;
		while (node->next)
			node = node->next;
		new->prev = node;
		node->next = new;
	}
	return (new);
}
