#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value associeted with a key
 * @ht: hash table
 * @key: key
 *
 * Return: value, or NULL if the key couldn't be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *head;
	unsigned long int index;

	if (ht == NULL)
		return (NULL);
	if (key == NULL || strlen(key) == 0)
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	head = ht->array[index];
	if (head == NULL)
		return (NULL);
	while (head && strcmp(head->key, key) != 0)
		head = head->next;
	if (head != NULL && strcmp(head->key, key) == 0)
		return (head->value);
	else
		return (NULL);
}
