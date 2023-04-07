#include "hash_tables.h"

/**
 * hash_node_delete - delete a hash_node_t linked list
 * @head: linked list
 */
void hash_node_delete(hash_node_t *head)
{
	hash_node_t *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->value);
		free(tmp);
	}
}

/**
 * hash_table_delete - deletes a hash table
 * @ht: hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *head;

	if (ht == NULL)
		return;
	for (i = 0; i < ht->size; i++)
	{
		head = ht->array[i];
		if (head)
			hash_node_delete(head);
	}
	free(ht->array);
	free(ht);
}
