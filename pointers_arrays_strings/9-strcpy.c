#include "main.h"

/**
 * _strcpy - copies a string
 * @dest: destination buffer
 * @src: source string
 *
 * Return: pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
	(void)src;
	for (int i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[strlen(src)] = '\0';

	return (dest);
}
