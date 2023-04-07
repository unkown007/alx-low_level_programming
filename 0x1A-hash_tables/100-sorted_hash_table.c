#include "hash_tables.h"

/**
 * shash_table_create - create a hash table
 * @size: size of the hash table
 *
 * Return:  address of hash table or NULL if it fail
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new;
	unsigned long int i;

	new = malloc(sizeof(shash_table_t));
	if (new == NULL)
		return (NULL);
	new->size = size;
	new->array = malloc(size * sizeof(shash_node_t *));
	if (new->array == NULL)
	{
		free(new);
		return (NULL);
	}
	for (i = 0; i < size; i++)
		new->array[i] = NULL;
	new->shead = NULL;
	new->stail = NULL;
	return (new);
}

/**
 * create_snode - create new shash_node_t node
 * @key: key
 * @value: value
 *
 * Return: address of the node, or NULL if it failed
 */
shash_node_t *create_snode(const char *key, const char *value)
{
	shash_node_t *node;

	node = malloc(sizeof(shash_node_t));
	if (node == NULL)
		return (NULL);
	node->key = strdup(key);
	node->value = strdup(value);
	node->next = NULL;
	node->sprev = NULL;
	node->snext = NULL;
	return (node);
}

/**
 * shash_table_set_ordered - insert the element in the right position
 * @ht: hash table
 * @new_node: hash node
 */
void shash_table_set_ordered(shash_table_t *ht, shash_node_t *new_node)
{
	shash_node_t *snode, *sprev;

	if (ht->shead == NULL)
	{
		ht->shead = new_node;
		ht->stail = new_node;
	}
	else
	{
		sprev = snode = ht->shead;
		while (snode && strcmp(snode->key, new_node->key) < 0)
		{
			sprev = snode;
			snode = snode->snext;
		}
		if (snode == NULL)
		{
			new_node->sprev = sprev;
			sprev->snext = new_node;
			ht->stail = new_node;
		}
		else if (snode == ht->shead)
		{
			new_node->snext = snode;
			snode->sprev = new_node;
			ht->shead = new_node;
		}
		else
		{
			sprev->snext = new_node;
			new_node->snext = snode;
			new_node->sprev = sprev;
			snode->sprev = new_node;
		}
	}
}

/**
 * shash_table_set - inserts a new element in the sorted hash table
 * @ht: hash table
 * @key: key(cannot be null or empty)
 * @value: value(must be duplicated)
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node;
	shash_node_t *node;
	unsigned long int index;

	if (ht == NULL || key == NULL || value == NULL)
		return (0);
	new_node = create_snode(key, value);
	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];
	if (node == NULL)
		ht->array[index] = new_node;
	else
	{
		if (strcmp(node->key, key) == 0)
		{
			strcpy(ht->array[index]->value, value);
			free(new_node->value);
			free(new_node);
			return (1);
		}
		else
		{
			new_node->next = node;
			ht->array[index] = new_node;
		}
	}
	shash_table_set_ordered(ht, new_node);
	return (1);
}

/**
 * shash_table_get - retrieves a value associeted with a key
 * @ht: hash table
 * @key: key
 *
 * Return: value, or NULL if the key couldn't be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *head;
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

/**
 * shash_table_print - prints a hash table
 * @ht: hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *head;

	if (ht == NULL)
	{
		return;
	}
	putchar('{');
	head = ht->shead;
	while (head)
	{
		printf("'%s': '%s'", head->key, head->value);
		if (head->snext)
			printf(", ");
		head = head->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a hash table in reverse order
 * @ht: hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *tail;

	if (ht == NULL)
	{
		return;
	}
	putchar('{');
	tail = ht->stail;
	while (tail)
	{
		printf("'%s': '%s'", tail->key, tail->value);
		if (tail->sprev)
			printf(", ");
		tail = tail->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - frees a hash table
 * @ht: hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *tmp, *node;

	node = ht->shead;
	while (node)
	{
		tmp = node;
		node = node->snext;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}
	free(ht->array);
	free(ht);
}
