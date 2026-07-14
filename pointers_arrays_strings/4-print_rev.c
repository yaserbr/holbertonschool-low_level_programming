#include "main.h"

/**
 * print_rev - prints a string in reverse
 * @s: string to print
 *
 * Return: Nothing.
 */
void print_rev(char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	while (len > 0)
	{
		len--;
		_putchar(s[len]);
	}
	_putchar('\n');
}
