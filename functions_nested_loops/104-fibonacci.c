#include <stdio.h>

/**
 * print_fibonacci - prints a Fibonacci number
 * @high: the high part of the number
 * @low: the low part of the number
 */
void print_fibonacci(unsigned long int high, unsigned long int low)
{
	if (high > 0)
	{
		printf("%lu%09lu", high, low);
	}
	else
	{
		printf("%lu", low);
	}
}

/**
 * main - prints the first 98 Fibonacci numbers
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int count;
	unsigned long int high1, low1, high2, low2;
	unsigned long int high_next, low_next, base;

	high1 = 0;
	low1 = 1;
	high2 = 0;
	low2 = 2;
	base = 1000000000;

	for (count = 1; count <= 98; count++)
	{
		print_fibonacci(high1, low1);

		if (count != 98)
		{
			printf(", ");
		}

		low_next = low1 + low2;
		high_next = high1 + high2 + (low_next / base);
		low_next %= base;
		high1 = high2;
		low1 = low2;
		high2 = high_next;
		low2 = low_next;
	}

	printf("\n");

	return (0);
}
