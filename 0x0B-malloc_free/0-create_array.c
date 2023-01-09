#include "main.h"
#include <stdlib.h>

/**
 * create_array - creates an array of char chars, and initializes it with
 * a specific char
 * @size: number of char bytes to be allocated
 * @c: character to initialize the array
 *
 * Return: an address or pointer to array
 */
char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *array;

	array = malloc(sizeof(char) * size);

	if (!c || !array)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = c;

	return ((char *) array);
}
