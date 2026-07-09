#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
	{
		/* طباعة الحرف فقط إذا لم يكن 'e' ولا 'q' */
		if (letter != 'e' && letter != 'q')
		{
			putchar(letter); /* الاستخدام الأول لـ putchar */
		}
	}
	
	putchar('\n'); /* الاستخدام الثاني لـ putchar */

	return (0);
}
