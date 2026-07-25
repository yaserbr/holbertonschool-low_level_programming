#include <stdio.h>
#include "dog.h"

/**
 * print_dog - prints a struct dog
 * @d: pointer to the struct dog to print
 */
void print_dog(struct dog *d)
{
	if (d == 0)
		return;

	printf("Name: %s\n", d->name == 0 ? "(nil)" : d->name);
	printf("Age: %f\n", d->age);
	printf("Owner: %s\n", d->owner == 0 ? "(nil)" : d->owner);
}
