#include "main.h"

/**
 * set_string - sets the value of a pointer to a char
 * @s: pointer to the pointer to set
 * @to: string to point to
 *
 * Return: Nothing.
 */
void set_string(char **s, char *to)
{
	*s = to;
}
