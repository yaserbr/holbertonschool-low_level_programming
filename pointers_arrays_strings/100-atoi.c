#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: integer found in the string, or 0 if no number is found.
 */
int _atoi(char *s)
{
	int i;
	int sign;
	unsigned int num;

	i = 0;
	sign = 1;
	num = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			sign *= -1;
		}
		if (s[i] >= '0' && s[i] <= '9')
		{
			while (s[i] >= '0' && s[i] <= '9')
			{
				num = (num * 10) + (s[i] - '0');
				i++;
			}
			break;
		}
		i++;
	}

	if (sign < 0)
	{
		return (-num);
	}
	return (num);
}
