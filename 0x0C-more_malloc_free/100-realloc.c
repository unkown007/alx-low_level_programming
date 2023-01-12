#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory block
 * @old_size: size of the memory block
 * @new_size: size of the new memory block
 *
 * Return: pointer to the new allocated memory or NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_mem;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		new_mem = malloc(new_size);
		if (new_mem == NULL)
			return (NULL);

		return (new_mem);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new_mem = malloc(new_size);
	if (new_mem == NULL)
		return (NULL);

	memcpy(new_mem, ptr, old_size);
	free(ptr);
	return (new_mem);
}
