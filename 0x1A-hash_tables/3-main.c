#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    hash_table_t *ht;

    ht = hash_table_create(1024);
    hash_table_set(ht, "betty", "cool");
    hash_table_set(ht, "hetairas", "praia");
    hash_table_set(ht, "mentioner", "maputo");
    hash_table_set(ht, "heliotropes", "bagamoyo");
    hash_table_set(ht, "neurospora", "igreja");
    hash_table_set(ht, "hetairas", "victor");
    hash_table_set(ht, "mentioner", "maputo mubukwana");
    hash_table_print(ht);
    hash_table_delete(ht);
    return (EXIT_SUCCESS);
}
