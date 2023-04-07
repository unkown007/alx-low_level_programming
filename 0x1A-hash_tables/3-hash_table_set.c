#include "hash_tables.h"

/**
 * create_node - create new node
 * @key: key
 * @value: value
 *
 * Return: pointer to node or NULL if it failed
 */
hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *node;

	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (NULL);
	node->key = (char *) key;
	node->value = strdup(value);
	node->next = NULL;
	return (node);
}

/**
 * hash_table_set - adds an element to the hash table
 * @ht: hash table
 * @key: key that cannot be empty
 * @value: value that can be an empty string
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node;
	hash_node_t *node, *tmp;
	unsigned long int index;
	char *str;

	if (ht == NULL)
		return (0);
	if (key == NULL || strlen(key) == 0 || value == NULL)
		return (0);
	new_node = create_node(key, value);
	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];
	if (node == NULL)
		ht->array[index] = new_node;
	else
	{
		tmp = node;
		while (tmp && strcmp(tmp->key, key) != 0)
			tmp = tmp->next;
		if (tmp != NULL)
		{
			str = tmp->value;
			tmp->value = strdup(value);
			free(str);
			free(new_node->value);
			free(new_node);
		}
		else
		{
			new_node->next = node;
			ht->array[index] = new_node;
		}
	}
	return (1);
}
