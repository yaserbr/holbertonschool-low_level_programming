#include "main.h"

/**
 * puts_half - prints the second half of a string
 * @str: string to print
 *
 * Return: Nothing.
 */
void puts_half(char *str)
{
	int len = 0;
	int i;

	while (str[len] != '\0')
	{
		len++;
	}
	len = len / 2 + (len % 2); /* If odd, start from the middle character */
	for (i = len; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
	(void)str;
}
