#include <stdlib.h>
#include "lists.h"

/**
 * free_list - frees a list_t list
 * @head: first element of the list
 */
void free_list(list_t *head)
{
	if (head == NULL)
		return;
	while (head)
	{
		free(head->str);
		free(head);
		head = head->next;
	}
}
