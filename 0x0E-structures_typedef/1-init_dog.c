#include <stdlib.h>
#include "dog.h"

/**
 * init_dog - initializes a variable
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner
 * @d: a variable
 *
 * Return: the variable
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != 0)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
