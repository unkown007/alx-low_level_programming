#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint_end - adds a new node at the beginning of a listint_t list
 * @head: head of the linked listint_t list
 * @n: number to be added
 *
 * Return: address of the new element, or NULL
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new;
	listint_t *tmp;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	tmp = *head;
	if (tmp != NULL)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*head = new;

	return (new);
}
