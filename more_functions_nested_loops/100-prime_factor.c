#include <math.h>
#include <stdio.h>

/**
 * main - prints the largest prime factor of 612852475143
 *
 * Return: Always 0
 */
int main(void)
{
	double number, factor, largest;

	number = 612852475143.0;
	largest = 1;

	for (factor = 2; factor * factor <= number; factor++)
	{
		while (fmod(number, factor) == 0)
		{
			largest = factor;
			number /= factor;
		}
	}

	if (number > largest)
		largest = number;

	printf("%.0f\n", largest);

	return (0);
}
