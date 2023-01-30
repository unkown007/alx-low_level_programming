#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index index of a
 * listint_t linked list
 * @head: head of listint_t linked list
 * @index: index
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *node;
	listint_t *delete;
	unsigned int i;

	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		node = *head;
		*head = (*head)->next;
		free(node);
		return (1);
	}
	for (node = *head, i = 0; i < index - 1 && node; i++, node = node->next)
		;
	if (node == NULL)
		return (-1);
	delete = node->next;
	node->next = delete->next;
	free(delete);
	return (1);
}
