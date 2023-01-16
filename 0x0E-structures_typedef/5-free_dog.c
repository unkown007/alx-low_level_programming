#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - frees dogs
 * @d: a variable of type dog_t
 */
void free_dog(dog_t *d)
{
	free(d);
}
