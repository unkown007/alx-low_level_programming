#include <stdlib.h>
#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: first element of the list
 *
 * Return: address of the node where the loop starts,
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *p1;
	listint_t *p2;

	if (head == NULL)
		return (NULL);
	p1 = p2 = head;
	p1 = p1->next;
	p2 = p2->next->next;
	while (p2 && p2->next)
	{
		if (p1 == p2)
		{
			p1 = head;
			break;
		}
		p1 = p1->next;
		p2 = p2->next->next;
	}
	if (!p1 || !p2 || !p2->next)
		return (NULL);
	while (p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return (p1);
}
