#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers from min to max
 * @min: starting value
 * @max: ending value
 *
 * Return: pointer to the new array, or NULL on failure
 */
int *array_range(int min, int max)
{

	char *ptr;
	int *array;
	int size ;

	size = max - min + 1;
	ptr = malloc(size * sizeof(int));
	if (ptr == NULL)
	{
		return (NULL);
	}
	array = (int *)ptr;

	while (size--)
	{
		array[size] = min + size;
	}

	return (array);
}
