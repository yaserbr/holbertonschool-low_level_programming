#include "main.h"

/**
 * rev_string - reverses a string
 * @s: string to reverse
 *
 * Return: Nothing.
 */
void rev_string(char *s)
{
	int len;
	int i;
	char temp;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	i = 0;
	len--;
	while (i < len)
	{
		temp = s[i];
		s[i] = s[len];
		s[len] = temp;
		i++;
		len--;
	}
}
