#include <stdio.h>
#include "main.h"

/**
 * print_array - prints n elements of an array of integers
 * @a: array to print
 * @n: number of elements to print
 *
 * Return: Nothing.
 */
void print_array(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		_putchar(a[i] + '0'); /* Convert integer to character */
		if (i < n - 1)
		{
			printf(", ");
		}
	}
	(void)a;
	(void)n;
}
