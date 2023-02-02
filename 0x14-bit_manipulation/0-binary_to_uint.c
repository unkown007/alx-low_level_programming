#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * auth - verifies existence of char that is not 0 or 1 in a string
 * @b: string
 *
 * Return: 1 if there is a char that is nor 0 or 1, 0 otherwise
 */
int auth(const char *b)
{
	if (*b == '\0')
		return (0);
	if (*b != '0' && *b != '1')
		return (1);
	return (auth(b + 1));
}

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: string of 0 and 1 chars
 *
 * Return: converted number, or 0 if
 * there is one or more chars in the string b that is not 0 or 1
 * b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int n = 0;
	int i, j;

	if (b == NULL || auth(b))
		return (0);
	for (i = strlen(b) - 1, j = 0; i >= 0; i--, j++)
		if (b[i] == '1')
			n += (1 << j);
	return (n);
}
