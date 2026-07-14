/**
 * swap_int - swaps the values of two integers
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 *
 * Return: Nothing.
 */
void swap_int(int *a, int *b)
{
	if (a != b)
	{
		*a = *a ^ *b;
		*b = *a ^ *b;
		*a = *a ^ *b;
	}
}
