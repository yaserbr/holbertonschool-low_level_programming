#include <stdlib.h>
#include "lists.h"

/**
 * free_dlistint - frees a dlistint_t list
 * @head: pointer to the head of the list
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
    unsigned int i;
    
    i= 0;

	while (i != index && head != NULL)
    {
        head = head->next;
        i++;
    }
    return (head);
}
