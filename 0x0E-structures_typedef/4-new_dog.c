#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: new allocated dog or NULL
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	unsigned int i, l1, l2;
	dog_t *d;

	if (name == NULL || owner == NULL)
		return (NULL);
	d = malloc(sizeof(dog_t));
	if (d == NULL)
		return (NULL);
	for (l1 = 0; name[l1]; l1++)
		;
	l1++;
	d->name = malloc(l1 * sizeof(char));
	if (d->name == NULL)
	{
		free(d);
		return (NULL);
	}
	for (i = 0; i < l1; i++)
		d->name[i] = name[i];
	d->age = age;
	for (l2 = 0; owner[l2]; l2++)
		;
	l2++;
	d->owner = malloc(l2 * sizeof(char));
	if (d->owner == NULL)
	{
		free(d->name);
		free(d);
		return (NULL);
	}
	for (i = 0; i < l2; i++)
		d->owner[i] = owner[i];
	return (d);
}
