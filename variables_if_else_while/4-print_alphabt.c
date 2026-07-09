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
		/* طباعة الحرف فقط إذا لم �
		if (letter != 'e' && letter != 'q')
		{
			putchar(letter); 
		}
	}
	
	putchar('\n'); 

	return (0);
}
