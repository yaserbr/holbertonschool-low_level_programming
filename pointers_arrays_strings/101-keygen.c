#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TARGET 2772
#define MIN_CHAR 33
#define MAX_CHAR 126
#define MIN_LEN 24
#define LEN_RANGE 12

/**
 * main - generates random valid passwords for 101-crackme
 *
 * Return: Always 0.
 */
int main(void)
{
	char password[100];
	int len;
	int i;
	int sum;
	int diff;
	int change;

	srand(time(NULL));
	len = MIN_LEN + (rand() % LEN_RANGE);
	sum = 0;
	i = 0;
	while (i < len)
	{
		password[i] = MIN_CHAR + (rand() % (MAX_CHAR - MIN_CHAR + 1));
		sum += password[i];
		i++;
	}

	diff = TARGET - sum;
	i = 0;
	while (diff != 0)
	{
		if (diff > 0)
		{
			change = MAX_CHAR - password[i];
			if (change > diff)
			{
				change = diff;
			}
			password[i] += change;
			diff -= change;
		}
		else
		{
			change = password[i] - MIN_CHAR;
			if (change > -diff)
			{
				change = -diff;
			}
			password[i] -= change;
			diff += change;
		}
		i++;
		if (i == len)
		{
			i = 0;
		}
	}

	i = 0;
	while (i < len)
	{
		putchar(password[i]);
		i++;
	}

	return (0);
}
