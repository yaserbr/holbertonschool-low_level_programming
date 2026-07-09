#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char letter;

	/* الحلقة الأولى: طباعة الحروف الصغيرة */
	for (letter = 'a'; letter <= 'z'; letter++)
	{
		putchar(letter);
	}

	/* الحلقة الثانية: طباعة الحروف الكبيرة */
	for (letter = 'A'; letter <= 'Z'; letter++)
	{
		putchar(letter);
	}

	/* طباعة سطر جديد في النهاية */
	putchar('\n');

	return (0);
}
