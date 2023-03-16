#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index of a
 * dlistint_t linked list
 * @head: head of a dlistint_t linked list
 * @index: position of the element
 *
 * Return: 1 if it succeeded, or -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *node;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);
	node = *head;
	while (node && i < index)
	{
		node =  node->next;
		i++;
	}
	if (i != index || node == NULL)
		return (-1);
	if (node == *head)
	{
		*head = node->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(node);
	}
	else
	{
		node->prev->next = node->next;

		if (node->next != NULL)
			node->next->prev = node->prev;
		free(node);
	}
	return (1);
}
