#include "main.h"

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
	int start;

	if (size_r <= 1)
		return (0);

	i = 0;
	while (n1[i] != '\0')
		i++;

	j = 0;
	while (n2[j] != '\0')
		j++;

	i--;
	j--;
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

	start = k + 1;
	i = 0;
	while (start < size_r - 1)
		r[i++] = r[start++];
	r[i] = '\0';

	return (r);
}
