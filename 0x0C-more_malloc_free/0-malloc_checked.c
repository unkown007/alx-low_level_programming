#include <stdlib.h>
#include "main.h"

/**
 * malloc_checked - allocates memory using malloc
 * if the malloc fails cause normal process termination with a status
 * value of 98
 * @b: size of the memory
 *
 * Return: a pointer to the memory
 */
void *malloc_checked(unsigned int b)
{
	void *mem;

	mem = malloc(b);

	if (mem == NULL)
		exit(98);

	return (mem);
}
