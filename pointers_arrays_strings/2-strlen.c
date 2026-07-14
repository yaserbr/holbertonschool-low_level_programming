/**
 * swap_int - swaps the values of two integers
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 *
 * Return: Nothing.
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
    {
        len++;
        s++;
    }
	return len;
}
