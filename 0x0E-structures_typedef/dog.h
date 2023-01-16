#ifndef DOG_H
#define DOG_H

/**
 * struct dog - dog definition;
 * @name: this is the name
 * @owner: this is the owner
 * @age: this is age
 *
 * Description: this data structure stores information of a dog;
 */
struct dog
{
	char *name;
	char *owner;
	float age;
};

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif
