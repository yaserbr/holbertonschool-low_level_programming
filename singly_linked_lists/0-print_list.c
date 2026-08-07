#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints all the elements of a list_t list
 * @h: pointer to the head of the list
 *
 * Return: number of nodes
 */
size_t print_list(const list_t *h)
{
	int count;
	
	count = 0;

	while (h)
	{
		count++;
		h = h->next;
	}

	return (count);
}
