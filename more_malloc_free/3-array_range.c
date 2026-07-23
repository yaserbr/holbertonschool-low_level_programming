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
	int *array;
	int size;

	if (min > max)
		return (NULL);
	size = max - min + 1;
	array = malloc(size * sizeof(int));
	if (array == NULL)
	{
		return (NULL);
	}

	while (size--)
	{
		array[size] = min + size;
	}

	return (array);
}
