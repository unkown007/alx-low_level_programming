#include "hash_tables.h"

/**
 * create_array - create the array of buckets
 * that will hold the data of the hash table
 * @size: length of the array
 *
 * Return: pointer to array of hash_node_t, or NULL if it fail
 */
hash_node_t **create_array(unsigned long int size)
{
	unsigned int i;
	hash_node_t **buckets;

	buckets = malloc(size * sizeof(hash_node_t *));
	if (buckets == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		buckets[i] = NULL;
	return (buckets);
}

/**
 * hash_table_create - creates a hash table
 * @size: length of the table
 *
 * Return: pointer to the hash, or NULL if it fail
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hashtable;

	hashtable = malloc(sizeof(hash_table_t));
	if (hashtable == NULL)
		return (NULL);
	hashtable->size = size;
	hashtable->array = create_array(hashtable->size);
	if (hashtable->array == NULL)
	{
		free(hashtable);
		return (NULL);
	}
	return (hashtable);
}
