#include <stdlib.h>
#include "lists.h"

/**
 * free_dlistint - frees a dlistint_t list
 * @head: head of a linked dllistint_t list
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *node;

	if (head == NULL)
		return;
	while (head)
	{
		node = head;
		head = head->next;
		free(node);
	}
}
