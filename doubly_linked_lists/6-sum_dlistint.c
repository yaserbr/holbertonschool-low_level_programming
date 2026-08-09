#include <stdlib.h>
#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t list
 * @head: pointer to the head of the list
 * @index: index of the node, starting from 0
 *
 * Return: the nth node, or NULL if the node does not exist
 */
int sum_dlistint(dlistint_t *head)
{
	int sum;
    
    sum = 0;

	while (head != NULL)
    { sum += head->n;
    head = head->next;
    }

	return (sum);
}
