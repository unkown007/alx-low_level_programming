#include "hash_tables.h"

/**
 * hash_djb2 - generate an hash code from a given string
 * @str: string
 *
 * Return: hash code
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}
	return (hash);
}
