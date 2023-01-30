#include <stdlib.h>
#include "lists.h"

/**
 * free_listint - frees a listint_t list
 * @head: head of the listint_t list
 */
void free_listint(listint_t *head)
{
	listint_t *tmp;

	if (head == NULL)
		return;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
