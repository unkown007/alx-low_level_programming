#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * add_address - add addresses of printed nodes of a listint_t linked list
 * @old_addr: addresses already printed
 * @size: number of addresses
 * @new_addr: new addr
 *
 * Return: pointer to listint_t linked list addr
 */
const listint_t **add_address(const listint_t **old_addr, size_t size,
		const listint_t *new_addr)
{
	const listint_t **new;
	size_t i;

	new = malloc(size * sizeof(listint_t *));
	if (new == NULL)
		exit(98);
	for (i = 0; i < size - 1; i++)
		new[i] = old_addr[i];
	new[i] = new_addr;
	free(old_addr);
	return (new);
}

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: head of a listint_t linked list
 *
 * Return: number of element of a listint_t linked list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t i, size = 0;
	const listint_t **addr = NULL;

	if  (head == NULL)
		return (0);
	while (head)
	{
		for (i = 0; i < size; i++)
		{
			if (head == addr[i])
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free(addr);
				return (size);
			}
		}
		size++;
		addr = add_address(addr, size, head);
		printf("[%p] %d\n", (void *) head, head->n);
		head = head->next;
	}
	free(addr);
	return (size);
}
