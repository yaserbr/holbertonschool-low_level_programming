#include "main.h"

/**
 * sqrt_helper - finds the natural square root of n
 * @n: number to check
 * @i: current candidate square root
 *
 * Return: i if i * i equals n, otherwise -1
 */
int sqrt_helper(int n, int i)
{
	if (n % i == 0 && n / i == i)
		return (i);
	if (i * i > n)
		return (-1);
	return (sqrt_helper(n, i + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to check
 *
 * Return: square root of n, or -1 if none exists
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (sqrt_helper(n, 0));
}
