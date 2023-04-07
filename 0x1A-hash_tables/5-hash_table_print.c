#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table
 * @ht: hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	int flag = 0;
	hash_node_t *head;

	if (ht == NULL)
	{
		printf("{}\n");
		return;
	}
	putchar('{');
	for (i = 0; i < ht->size; i++)
	{
		head = ht->array[i];
		while (head)
		{
			if (flag != 0)
				printf(", ");
			flag = 1;
			printf("'%s': '%s'", head->key, head->value);
			flag = 1;
			head = head->next;
		}
	}
	printf("}\n");
}
