#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * print_dog - prints a struct dog
 * @d: variable of type struct dog
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
	{
		putchar('\n');
		return;
	}
	printf("Name: %s\nAge: %f\nOwner: %s\n",
			d->name != NULL ? d->name : "(nil)",
			d->age,
			d->owner);
}
