#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: head of the list_t list
 * @str: string to be added
 *
 * Return: Address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new;
	list_t *node;

	node = *head;
	if (*head != NULL)
		while (node->next != NULL)
			node = node->next;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	new->len = strlen(str);
	new->next = NULL;
	if (node == NULL)
		*head = new;
	else
		node->next = new;
	return (new);
}
