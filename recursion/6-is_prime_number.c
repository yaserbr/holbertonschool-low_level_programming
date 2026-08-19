#include "main.h"

/**
 * prime_helper - checks if n has a divisor up to its square root
 * @n: the number to check
 * @i: the current divisor to check
 *
 * Return: 1 if n is a prime number, 0 otherwise
 */
int prime_helper(int n, int i)
{
	if (i * i > n)
		return (1);
	if (n % i == 0)
		return (0);
	return (prime_helper(n, i + 1));
}

/**
 * is_prime_number - checks if a number is prime
 * @n: the number to check
 *
 * Return: 1 if n is a prime number, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);

	return (prime_helper(n, 2));
}
