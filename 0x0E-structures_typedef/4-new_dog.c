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
	int i, l1;

	if (name == NULL || owner == NULL)
		return (NULL);
	d = malloc(sizeof(struct dog));
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
	/*d->name[i] = '\0';*/

	d->age = age;

	d->owner = malloc((strlen(owner) + 1) * sizeof(char));
	if (d->owner == NULL)
	{
		free(d->owner);
		free(d);
		return (NULL);
	}
	for (i = 0; owner[i]; i++)
		d->owner[i] = owner[i];
	d->owner[i] = '\0';

	return (d);
}
