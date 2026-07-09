#include <stdio.h>

/**
 * main - prints the sum of even Fibonacci terms below 4000000
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long int first;
	unsigned long int second;
	unsigned long int next;
	unsigned long int sum;

	first = 1;
	second = 2;
	sum = 2;

	while (1)
	{
		next = first + second;

		if (next > 4000000)
		{
			break;
		}

		if ((next % 2) == 0)
		{
			sum += next;
		}

		first = second;
		second = next;
	}

	printf("%lu\n", sum);

	return (0);
}
