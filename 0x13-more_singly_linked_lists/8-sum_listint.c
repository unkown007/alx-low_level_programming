#include <stdlib.h>
#include "lists.h"

/**
 * sum_listint - computes the sum of all the data(n)
 * of a listint_t linked list
 * @head: head of a listint_t linked list
 *
 * Return: sum of all data(n)
 */
int sum_listint(listint_t *head)
{
	if (head == NULL)
		return (0);
	return (head->n + sum_listint(head->next));
}
