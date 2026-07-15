#include "main.h"

/**
 * rot13 - encodes a string using rot13
 * @str: string to encode
 *
 * Return: pointer to str.
 */
char *rot13(char *str)
{
	int i;
	int base;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z') ||
		    (str[i] >= 'A' && str[i] <= 'Z'))
		{
			base = 'A' + ((str[i] >= 'a') * 32);
			str[i] = ((str[i] - base + 13) % 26) + base;
		}
		i++;
	}

	return (str);
}
