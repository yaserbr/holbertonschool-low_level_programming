#include "main.h"

/**
 * num_len - returns the length of a number string
 * @num: number string
 *
 * Return: length of num.
 */
int num_len(char *num)
{
	int i;

	i = 0;
	while (num[i] != '\0')
		i++;

	return (i);
}

/**
 * move_result - moves the result to the beginning of the buffer
 * @r: buffer used to store the result
 * @start: first digit of the result
 * @end: end of the result area
 *
 * Return: pointer to r.
 */
char *move_result(char *r, int start, int end)
{
	int i;

	i = 0;
	while (start < end)
		r[i++] = r[start++];
	r[i] = '\0';

	return (r);
}

/**
 * infinite_add - adds two numbers
 * @n1: first number
 * @n2: second number
 * @r: buffer used to store the result
 * @size_r: size of the buffer
 *
 * Return: pointer to r, or 0 if the result does not fit.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i;
	int j;
	int k;
	int sum;
	int carry;

	if (size_r <= 1)
		return (0);

	i = num_len(n1) - 1;
	j = num_len(n2) - 1;
	k = size_r - 2;
	carry = 0;
	while (i >= 0 || j >= 0 || carry)
	{
		if (k < 0)
			return (0);

		sum = carry;
		if (i >= 0)
			sum = sum + n1[i--] - '0';
		if (j >= 0)
			sum = sum + n2[j--] - '0';

		r[k] = (sum % 10) + '0';
		carry = sum / 10;
		k--;
	}

	return (move_result(r, k + 1, size_r - 1));
}
