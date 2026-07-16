#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: string to search
 * @accept: string containing accepted bytes
 *
 * Return: number of bytes in the initial segment of s from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	int i, j;
	unsigned int sum;

	sum = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
				break;
		}

		if (accept[j] == '\0')
			return (sum);

		sum++;
	}

	return (sum);
}
