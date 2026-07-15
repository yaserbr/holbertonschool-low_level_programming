#include "main.h"
#include <stdio.h>

/**
 * print_hex - prints the hexadecimal content of a buffer line
 * @b: buffer to print
 * @start: first byte position of the line
 * @size: total size of the buffer
 *
 * Return: nothing.
 */
void print_hex(char *b, int start, int size)
{
	int i;

	i = 0;
	while (i < 10)
	{
		if (start + i < size)
			printf("%02x", (unsigned char)b[start + i]);
		else
			printf("  ");

		if (i % 2)
			printf(" ");
		i++;
	}
}

/**
 * print_chars - prints the printable content of a buffer line
 * @b: buffer to print
 * @start: first byte position of the line
 * @size: total size of the buffer
 *
 * Return: nothing.
 */
void print_chars(char *b, int start, int size)
{
	int i;

	i = 0;
	while (i < 10 && start + i < size)
	{
		if (b[start + i] >= 32 && b[start + i] <= 126)
			printf("%c", b[start + i]);
		else
			printf(".");
		i++;
	}
}

/**
 * print_buffer - prints a buffer
 * @b: buffer to print
 * @size: number of bytes to print
 *
 * Return: nothing.
 */
void print_buffer(char *b, int size)
{
	int i;

	if (size <= 0)
	{
		printf("\n");
		return;
	}

	i = 0;
	while (i < size)
	{
		printf("%08x: ", i);
		print_hex(b, i, size);
		print_chars(b, i, size);
		printf("\n");
		i = i + 10;
	}
}
