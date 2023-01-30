#include <stdlib.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: head of a listint_t linked list
 * @idx: index
 * @n: new node data(n)
 *
 * Return: address of the new node, or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *node;
	listint_t *new;
	unsigned int i;

	if (*head == NULL && idx != 0)
		return (NULL);
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
	}
	else if (idx == 0)
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		for (node = *head, i = 0; i < idx - 1 && node; i++, node = node->next)
			;
		if (node == NULL)
			return (NULL);
		else if (node->next == NULL)
			new->next = NULL;
		else
			new->next = node->next;
		node->next = new;
	}
	return (new);
}
