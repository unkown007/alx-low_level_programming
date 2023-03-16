#include <stdlib.h>
#include "lists.h"

/**
 * sum_dlistint - computes the sum of all the data(n) of a
 * dlistint_t linked list
 * @head: head of a dlistint linked list
 *
 * Return: sum of all the data
 */
int sum_dlistint(dlistint_t *head)
{
	if (head == NULL)
		return (0);
	return (head->n + sum_dlistint(head->next));
}
