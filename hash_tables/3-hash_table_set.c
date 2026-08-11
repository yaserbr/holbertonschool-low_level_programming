#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * update_node - Updates a hash node value.
 * @node: Node to update.
 * @value: New value.
 *
 * Return: 1 on success, 0 on failure.
 */
static int update_node(hash_node_t *node, const char *value)
{
	char *value_copy;

	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);
	free(node->value);
	node->value = value_copy;

	return (1);
}

/**
 * create_node - Creates a new hash node.
 * @key: Key to copy into the node.
 * @value: Value associated with the key.
 *
 * Return: Pointer to the new node, or NULL on failure.
 */
static hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *new_node;

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (NULL);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (NULL);
	}

	return (new_node);
}

/**
 * hash_table_set - Adds or updates an element in a hash table.
 * @ht: Hash table to add or update the key/value pair in.
 * @key: Key to add or update.
 * @value: Value associated with the key.
 *
 * Return: 1 on success, 0 on failure.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *node, *new_node;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
	    key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];
	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (update_node(node, value));
		node = node->next;
	}

	new_node = create_node(key, value);
	if (new_node == NULL)
		return (0);
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
