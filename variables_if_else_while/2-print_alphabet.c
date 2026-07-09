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
		putchar(letter); /* الاستخدام الأول: لطباعة الحروف داخل حلقة التكرار */
	}
	putchar('\n'); /* الاستخدام الثاني: لطباعة سطر جديد بعد انتهاء الحلقة */

	return (0);
}
