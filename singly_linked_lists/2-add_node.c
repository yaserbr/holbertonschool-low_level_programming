#include <stdio.h>
#include "lists.h"


list_t *add_node(list_t **head, const char *str){
    
    list_t *new_node = malloc(sizeof(list_t));
    if (new_node == NULL) {
        return NULL; // Memory allocation failed
    }

    new_node->str = strdup(str); // Duplicate the string
    if (new_node->str == NULL) {
        free(new_node); // Free the allocated memory for the node
        return NULL; // Memory allocation failed
    }

    new_node->len = strlen(str); // Set the length of the string
    new_node->next = *head; // Point to the current head of the list
    *head = new_node; // Update the head to point to the new node

    return new_node; // Return the newly created node
}
