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
	dog_t *d;
	int i;

	if (name == NULL || owner == NULL)
		return (NULL);
	d = malloc(sizeof(struct dog));
	if (d == NULL)
		return (NULL);
	/*if (name != NULL)
	{*/
		d->name = malloc((strlen(name) + 1) * sizeof(char));
		if (d->name == NULL)
			return (NULL);
		for (i = 0; name[i]; i++)
			d->name[i] = name[i];
		d->name[i] = '\0';
	/*} else
	{
		d->name = malloc(1 * sizeof(char));
		if (d->name == NULL)
			return (NULL);
		d->name[0] = '\0';
	}*/
	d->age = age;
	/*if (owner != NULL)
	{*/
		d->owner = malloc((strlen(owner) + 1) * sizeof(char));
		if (d->owner == NULL)
			return (NULL);
		for (i = 0; owner[i]; i++)
			d->owner[i] = owner[i];
		d->owner[i] = '\0';
	/*} else
	{
		d->owner = malloc(1 * sizeof(char));
		if (d->owner == NULL)
			return (NULL);
		d->owner[0] = '\0';
	}*/
	return (d);
}
