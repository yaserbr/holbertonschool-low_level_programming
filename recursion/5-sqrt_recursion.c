#include "main.h"

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: the number to calculate the square root of
 *
 * Return: the natural square root of n, or -1 if n has none
 */
int _sqrt_recursion(int n)
{
	int i = 0;
	int result;

	if (n < 0)
		return (-1);

	if (i * i == n)
	{
		result = i;
		i = 0;
		return (result);
	}

	if (i * i > n)
	{
		i = 0;
		return (-1);
	}

	i++;
	return (_sqrt_recursion(n));
}
