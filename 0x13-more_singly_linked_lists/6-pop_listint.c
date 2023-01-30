#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: head of a listint_t list
 *
 * Return: head node's data(n).
 */
int pop_listint(listint_t **head)
{
	listint_t *node;
	int n;

	if (*head == NULL)
		return (0);
	node = *head;
	n = node->n;
	*head = (*head)->next;
	free(node);
	return (n);
}
