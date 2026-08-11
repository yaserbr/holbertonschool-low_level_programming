#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: Size of the array.
 *
 * Return: Pointer to the new sorted hash table, or NULL on failure.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}
	ht->size = size;
	ht->shead = NULL;
	ht->stail = NULL;
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	return (ht);
}

/**
 * update_node - Updates a sorted hash node value.
 * @node: Node to update.
 * @value: New value.
 *
 * Return: 1 on success, 0 on failure.
 */
static int update_node(shash_node_t *node, const char *value)
{
	char *copy;

	copy = strdup(value);
	if (copy == NULL)
		return (0);
	free(node->value);
	node->value = copy;

	return (1);
}

/**
 * create_node - Creates a sorted hash node.
 * @key: Key to copy.
 * @value: Value to copy.
 *
 * Return: Pointer to the new node, or NULL on failure.
 */
static shash_node_t *create_node(const char *key, const char *value)
{
	shash_node_t *node;

	node = malloc(sizeof(shash_node_t));
	if (node == NULL)
		return (NULL);
	node->key = strdup(key);
	node->value = strdup(value);
	if (node->key == NULL || node->value == NULL)
	{
		free(node->key);
		free(node->value);
		free(node);
		return (NULL);
	}
	node->next = NULL;
	node->sprev = NULL;
	node->snext = NULL;

	return (node);
}

/**
 * sorted_insert - Inserts a node into the sorted linked list.
 * @ht: Sorted hash table.
 * @node: Node to insert.
 */
static void sorted_insert(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *current;

	if (ht->shead == NULL)
	{
		ht->shead = node;
		ht->stail = node;
		return;
	}
	current = ht->shead;
	while (current != NULL && strcmp(current->key, node->key) < 0)
		current = current->snext;
	if (current == NULL)
	{
		node->sprev = ht->stail;
		ht->stail->snext = node;
		ht->stail = node;
		return;
	}
	node->snext = current;
	node->sprev = current->sprev;
	if (current->sprev != NULL)
		current->sprev->snext = node;
	else
		ht->shead = node;
	current->sprev = node;
}

/**
 * shash_table_set - Adds or updates a sorted hash table element.
 * @ht: Sorted hash table.
 * @key: Key to add or update.
 * @value: Value associated with the key.
 *
 * Return: 1 on success, 0 on failure.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *node;

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
	node = create_node(key, value);
	if (node == NULL)
		return (0);
	node->next = ht->array[index];
	ht->array[index] = node;
	sorted_insert(ht, node);

	return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key.
 * @ht: Sorted hash table.
 * @key: Key to look for.
 *
 * Return: Value associated with the key, or NULL if not found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *node;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
	    key == NULL || *key == '\0')
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];
	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}

	return (NULL);
}

/**
 * print_list - Prints a sorted hash table linked list.
 * @node: First node to print.
 * @reverse: Whether to walk the list backwards.
 */
static void print_list(const shash_node_t *node, int reverse)
{
	const char *separator;

	separator = "";
	printf("{");
	while (node != NULL)
	{
		printf("%s'%s': '%s'", separator, node->key, node->value);
		separator = ", ";
		if (reverse)
			node = node->sprev;
		else
			node = node->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print - Prints a sorted hash table.
 * @ht: Sorted hash table to print.
 */
void shash_table_print(const shash_table_t *ht)
{
	if (ht == NULL)
		return;
	print_list(ht->shead, 0);
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse.
 * @ht: Sorted hash table to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	if (ht == NULL)
		return;
	print_list(ht->stail, 1);
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: Sorted hash table to delete.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *next;

	if (ht == NULL)
		return;
	node = ht->shead;
	while (node != NULL)
	{
		next = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = next;
	}
	free(ht->array);
	free(ht);
}
