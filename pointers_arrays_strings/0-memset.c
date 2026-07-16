#include "main.h"

/**
 * _memset - fills memory with a constant byte
 * @s: pointer to the memory area
 * @b: byte to fill memory with
 * @n: number of bytes to fill
 *
 * Return: pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
while (n--)
{
s[n] = b;
	
}

return (s);
}
