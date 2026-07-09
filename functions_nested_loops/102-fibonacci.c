#include <stdio.h>

/**
 * main - prints the first 50 Fibonacci numbers
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int count;
	unsigned long int first;
	unsigned long int second;
	unsigned long int next;

	first = 1;
	second = 2;

	for (count = 1; count <= 50; count++)
	{
		if (count == 1)
		{
			printf("%lu", first);
		}
		else if (count == 2)
		{
			printf("%lu", second);
		}
		else
		{
			next = first + second;
			printf("%lu", next);
			first = second;
			second = next;
		}

		if (count != 50)
		{
			printf(", ");
		}
	}

	printf("\n");

	return (0);
}
