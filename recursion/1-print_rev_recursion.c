#include "main.h"
/**
 * _print_rev_recursion - prints a string in reverse, followed by a new line, using recursion
 * @s: the string to print in reverse
 *
 * Return: void (nothing)
 */
void _print_rev_recursion(char *s)
{
	if (*s == '\0')
		return;

	_print_rev_recursion(s + 1);
	_putchar(*s);
}
