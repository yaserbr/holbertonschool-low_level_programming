#include "main.h"

/**
 * reverse_array - reverses the content of an array of integers
 * @a: array of integers
 * @n: number of elements in the array
 *
 * Return: nothing.
 */
void reverse_array(int *a, int n)
{
	int i = 0;
	n--;
	while (i < n)
	{
		int temp = a[i];
		a[i] = a[n];
		a[n] = temp;
		i++;
		n--;
	}
}
