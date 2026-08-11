#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table.
 * @ht: Hash table to print.
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	const hash_node_t *node;
	const char *separator;

	if (ht == NULL || ht->array == NULL)
		return;

	separator = "";
	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node != NULL)
		{
			printf("%s'%s': '%s'", separator, node->key, node->value);
			separator = ", ";
			node = node->next;
		}
	}
	printf("}\n");
}
