#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * _calloc -  allocates memory for an array, using malloc
 * @nmemb: number of members of the array
 * @size: size of each member of the array
 *
 * Return: pointer to the allocated memory or NULL
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *mem;

	if (nmemb == 0 || size == 0)
		return (NULL);

	mem = malloc(nmemb * size);
	if (mem == NULL)
		return (NULL);

	memset(mem, 0x0, nmemb * size);

	return (mem);
}
