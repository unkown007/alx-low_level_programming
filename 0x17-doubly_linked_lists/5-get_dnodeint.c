#include <stdlib.h>
#include "lists.h"

/**
 * get_dnodeint_at_index - gets nth node of a dlistint linked list
 * @head: head of a dlistint_t linked list
 * @index: index to get int the list
 *
 * Return: the nth node, or NULL
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;

	while (head && i < index)
	{
		head = head->next;
		i++;
	}
	return (head);
}
