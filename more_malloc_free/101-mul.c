#include "main.h"
#include <stdlib.h>

/**
 * print_error - prints Error and exits with status 98
 *
 * Return: Nothing
 */
void print_error(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}

/**
 * _strlen - returns the length of a string
 * @s: string to measure
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;

	return (len);
}

/**
 * is_digits - checks whether a string is composed only of digits
 * @s: string to check
 *
 * Return: 1 if only digits, 0 otherwise
 */
int is_digits(char *s)
{
	int i;

	i = 0;
	if (s[i] == '\0')
		return (0);

	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}

	return (1);
}

/**
 * is_zero - checks whether a string represents zero
 * @s: string to check
 *
 * Return: 1 if the number is zero, 0 otherwise
 */
int is_zero(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '0')
			return (0);
		i++;
	}

	return (1);
}

/**
 * init_array - initializes an integer array with zeros
 * @array: array to initialize
 * @size: number of elements
 *
 * Return: Nothing
 */
void init_array(int *array, int size)
{
	int i;

	for (i = 0; i < size; i++)
		array[i] = 0;
}

/**
 * multiply - multiplies two positive numbers stored as strings
 * @num1: first number
 * @num2: second number
 * @result: array used to store the result digits
 * @len1: length of the first number
 * @len2: length of the second number
 *
 * Return: Nothing
 */
void multiply(char *num1, char *num2, int *result, int len1, int len2)
{
	int i, j, n1, n2, sum;

	for (i = len1 - 1; i >= 0; i--)
	{
		n1 = num1[i] - '0';
		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			sum = (n1 * n2) + result[i + j + 1];
			result[i + j + 1] = sum % 10;
			result[i + j] += sum / 10;
		}
	}
}

/**
 * print_result - prints the multiplication result
 * @result: array containing result digits
 * @size: size of the result array
 *
 * Return: Nothing
 */
void print_result(int *result, int size)
{
	int i;

	i = 0;
	while (i < size - 1 && result[i] == 0)
		i++;

	while (i < size)
	{
		_putchar(result[i] + '0');
		i++;
	}
	_putchar('\n');
}

/**
 * main - multiplies two positive numbers
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int len1, len2, size;
	int *result;

	if (argc != 3)
		print_error();

	if (!is_digits(argv[1]) || !is_digits(argv[2]))
		print_error();

	if (is_zero(argv[1]) || is_zero(argv[2]))
	{
		_putchar('0');
		_putchar('\n');
		return (0);
	}

	len1 = _strlen(argv[1]);
	len2 = _strlen(argv[2]);
	size = len1 + len2;

	result = malloc(sizeof(int) * size);
	if (result == NULL)
		print_error();

	init_array(result, size);
	multiply(argv[1], argv[2], result, len1, len2);
	print_result(result, size);

	free(result);
	return (0);
}
