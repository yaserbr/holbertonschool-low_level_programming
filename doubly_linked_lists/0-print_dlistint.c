#include <stdio.h>
#include "lists.h"

/**
 * print_dlistint - prints all the elements of a dlistint_t list
 * @h: pointer to the first node
 *
 * Return: the number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{

    if (h == NULL)
        return (0);

    while (h != NULL)
    {
        printf("%d\n", h->n);
        h = h->next;
    }

    return (0);
}
