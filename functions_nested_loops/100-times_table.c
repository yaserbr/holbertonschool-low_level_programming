#include "main.h"

/**
 * print_number - prints a positive integer
 * @n: the integer to print
 */
static void print_number(int n)
{
	if (n >= 100)
	{
		_putchar((n / 100) + '0');
		_putchar(((n / 10) % 10) + '0');
	}
	else if (n >= 10)
	{
		_putchar((n / 10) + '0');
	}

	_putchar((n % 10) + '0');
}

/**
 * print_times_table - prints the n times table
 * @n: the times table size
 */
void print_times_table(int n)
{
	int row;
	int column;
	int product;

	if (n < 0 || n > 15)
	{
		return;
	}

	for (row = 0; row <= n; row++)
	{
		for (column = 0; column <= n; column++)
		{
			product = row * column;

			if (column != 0)
			{
				_putchar(',');
				_putchar(' ');

				if (product < 10)
				{
					_putchar(' ');
					_putchar(' ');
				}
				else if (product < 100)
				{
					_putchar(' ');
				}
			}

			print_number(product);
		}

		_putchar('\n');
	}
}
