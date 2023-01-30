#include <stdlib.h>
#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list
 * @head: head of a listint_t linked list
 *
 * Return: a pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev;
	listint_t *node;

	if (*head == NULL)
		return (NULL);
	node = *head;
	prev = *head;
	node = node->next;
	prev->next = NULL;
	while (node)
	{
		*head = node->next;
		node->next = prev;
		prev = node;
		node = *head;
	}
	*head = prev;
	return (*head);
}
