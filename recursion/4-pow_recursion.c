#include "main.h"
/**
 * factorial - returns the factorial of a given number
 * @n: the number to calculate the factorial of
 *
 * Return: the factorial of n, or -1 if n is negative
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	return (x * _pow_recursion(x, y - 1));
}
