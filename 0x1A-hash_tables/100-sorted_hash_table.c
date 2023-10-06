#include "hash_tables.h"
/**
 * shash_table_create - Creates a new hash table
 * @size: The size of the hash table
 *
 * Return: A pointer to the newly created hash table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *table;

	/* Allocate memory for the new hash table */
	table = malloc(sizeof(shash_table_t));
	if (table == NULL)
		return (NULL);

	table->size = size;
	table->shead = NULL;
	table->stail = NULL;

	/* Allocate memory for the array of hash nodes */
	table->array = malloc(sizeof(shash_node_t *) * size);
	if (table->array == NULL)
	{
		free(table);
		return (NULL);
	}

	/* Initialize each element of the array to NULL */
	for (unsigned long int index = 0; index < size; index++)
		table->array[index] = NULL;

	return (table);
}


/**
 * shash_sorted_list_update - Updates a node in a sorted hash table list
 * @ht: Pointer to the hash table
 * @new_node: Pointer to the new node to be updated
 * @key: The key of the node to be updated
 * @value: The new value for the node
 *
 * Return: 1 if the node was updated successfully, 0 otherwise
 */
int shash_sorted_list_update(shash_table_t **ht, shash_node_t **new_node,
                             const char *key, const char *value)
{
        shash_node_t *old_head = (*ht)->shead;

        /* Traverse the sorted list */
        while (old_head)
        {
                /* Check if the key matches */
                if (strcmp(old_head->key, key) == 0)
                {
                        /* Update the value */
                        free(old_head->value);
                        old_head->value = strdup(value);
                        
                        /* Free memory for the new node */
                        free((*new_node)->key);
                        free((*new_node)->value);
                        free((*new_node));
                        
                        return (1);
                }
                old_head = old_head->snext;
        }
        
        return (0);
}

/**
 * shash_sorted_list_insert - Inserts a node into a sorted hash table list
 * @ht: Pointer to the hash table
 * @new_node: Pointer to the new node to be inserted
 * @key: The key of the new node
 *
 * Return: 1 if the node was inserted successfully, 0 otherwise
 */
int shash_sorted_list_insert(shash_table_t **ht, shash_node_t **new_node,
                             const char *key)
{
        shash_node_t *old_head = (*ht)->shead;

        /* Traverse the sorted list */
        while (old_head)
        {
                /* Check if the key is greater */
                if (strcmp(old_head->key, key) > 0)
                {
                        /* Insert the new node before the current node */
                        (*new_node)->snext = old_head;
                        (*new_node)->sprev = old_head->sprev;
                        if (old_head->sprev != NULL)
                                old_head->sprev->snext = *new_node;
                        else
                                (*ht)->shead = *new_node;
                        old_head->sprev = *new_node;
                        
                        return (1);
                }
                old_head = old_head->snext;
        }
        
        /* Insert the new node at the end of the list */
        (*new_node)->sprev = (*ht)->stail;
        (*ht)->stail->snext = *new_node;
        (*ht)->stail = *new_node;
        
        return (1);
}

/**
 * shash_insert_into_sorted_list - Inserts a node into a sorted hash table list
 * @ht: Pointer to the hash table
 * @key: The key of the new node
 * @value: The value of the new node
 *
 * Return: 1 if the node was inserted successfully, 0 otherwise
 */
int shash_insert_into_sorted_list(shash_table_t *ht, const char *key,
                                  const char *value)
{
        shash_node_t *new_node = malloc(sizeof(shash_node_t));

        /* Check for memory allocation failure */
        if (new_node == NULL)
                return (0);

        /* Initialize the new node */
        new_node->key = strdup(key);
        new_node->value = strdup(value);
        new_node->next = new_node->snext = new_node->sprev = NULL;

        /* Check if the sorted list is empty */
        if (ht->shead == NULL && ht->stail == NULL)
        {
                /* Set the new node as the head and tail */
                ht->shead = new_node;
                ht->stail = new_node;
                return (1);
        }
        else
        {
                /* Try updating the node first, if not successful, insert it */
                if (!shash_sorted_list_update(&ht, &new_node, key, value))
                        return (shash_sorted_list_insert(&ht, &new_node, key));
                else
                        return (1);
        }
}

/**
 * shash_insert_into_array - Inserts a node into a hash table array
 * @ht: Pointer to the hash table
 * @key: The key of the new node
 * @value: The value of the new node
 *
 * Return: 1 if the node was inserted successfully, 0 otherwise
 */
int shash_insert_into_array(shash_table_t *ht, const char *key,
                            const char *value)
{
        unsigned long int index = 0;
        shash_node_t *new_node = malloc(sizeof(shash_node_t));
        shash_node_t *old_head = NULL;

        /* Check for memory allocation failure */
        if (new_node == NULL)
                return (0);

        /* Calculate the index for the key */
        index = key_index((const unsigned char *)key, ht->size);

        /* Initialize the new node */
        new_node->key = strdup(key);
        new_node->value = strdup(value);
        new_node->next = new_node->snext = new_node->sprev = NULL;

        /* Check if the array slot is empty */
        if ((ht->array)[index] == NULL)
        {
                /* Set the new node as the head of the array slot */
                (ht->array)[index] = new_node;
                return (1);
        }
        else
        {
                /* Traverse the linked list at the array slot */
                old_head = (ht->array)[index];
                while (old_head)
                {
                        /* Check if the key already exists */
                        if (strcmp(old_head->key, key) == 0)
                        {
                                /* Update the value */
                                free(old_head->value);
                                old_head->value = strdup(value);

                                /* Free memory for the new node */
                                free(new_node->key);
                                free(new_node->value);
                                free(new_node);

                                return (1);
                        }
                        old_head = old_head->next;
                }

                /* Insert the new node at the beginning of the linked list */
                old_head = (ht->array)[index];
                new_node->next = old_head;
                (ht->array)[index] = new_node;

                return (1);
        }
}

/**
 * shash_table_set - Sets a key-value pair in a sorted hash table
 * @ht: Pointer to the hash table
 * @key: The key to set
 * @value: The value to associate with the key
 *
 * Return: 1 if the key-value pair was set successfully, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
        /* Check for NULL pointers or empty key */
        if (key == NULL || value == NULL || ht == NULL || strlen(key) == 0)
                return (0);

        /* Insert into the array */
        if (!shash_insert_into_array(ht, key, value))
                return (0);

        /* Insert into the sorted list */
        return (shash_insert_into_sorted_list(ht, key, value));
}


/**
 * shash_table_get - Retrieves the value associated with a given key in a sorted hash table
 * @ht: Pointer to the hash table
 * @key: The key to search for
 *
 * Return: The value associated with the key, or NULL if the key is not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
        unsigned long int index;
        shash_node_t *current_node;

        /* Check for NULL pointers */
        if (ht == NULL || key == NULL)
                return (NULL);

        /* Calculate the index for the key */
        index = key_index((const unsigned char *)key, ht->size);

        /* Check if the array slot is empty */
        if ((ht->array)[index] == NULL)
                return (NULL);

        /* Traverse the linked list at the array slot */
        current_node = (ht->array)[index];
        while (current_node)
        {
                /* Check if the key matches */
                if (strcmp(current_node->key, key) == 0)
                        return (current_node->value);

                current_node = current_node->next;
        }

        return (NULL);
}

/**
 * shash_table_print - Prints the key-value pairs of a sorted hash table
 * @ht: Pointer to the hash table
 */
void shash_table_print(const shash_table_t *ht)
{
        shash_node_t *current_node;
        int is_first_hash;

        /* Check for NULL pointer */
        if (ht == NULL)
                return;

        /* Print opening brace */
        printf("{");

        /* Initialize flag for first key-value pair */
        is_first_hash = 1;

        /* Traverse the sorted linked list */
        current_node = ht->shead;
        while (current_node)
        {
                /* Print comma separator if not the first key-value pair */
                if (!is_first_hash)
                        printf(", ");
                is_first_hash = 0;

                /* Print the key-value pair */
                printf("\'%s\': \'%s\'", current_node->key,
                       current_node->value);

                /* Move to the next node */
                current_node = current_node->snext;
        }

        /* Print closing brace and newline */
        printf("}\n");
}


/**
 * shash_table_print_rev - Prints the key-value pairs of a sorted hash table in reverse order
 * @ht: Pointer to the hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
        shash_node_t *current_node;
        int is_first_hash;

        /* Check for NULL pointer */
        if (ht == NULL)
                return;

        /* Print opening brace */
        printf("{");

        /* Initialize flag for first key-value pair */
        is_first_hash = 1;

        /* Start from the tail of the sorted linked list */
        current_node = ht->stail;

        /* Traverse the sorted linked list in reverse order */
        while (current_node)
        {
                /* Print comma separator if not the first key-value pair */
                if (!is_first_hash)
                        printf(", ");
                is_first_hash = 0;

                /* Print the key-value pair */
                printf("\'%s\': \'%s\'", current_node->key,
                       current_node->value);

                /* Move to the previous node */
                current_node = current_node->sprev;
        }

        /* Print closing brace and newline */
        printf("}\n");
}

/**
 * shash_table_delete_arr - Deletes a sorted hash table and frees the memory
 * @ht: Pointer to the hash table
 */
void shash_table_delete_arr(shash_table_t *ht)
{
        shash_node_t *current_node, *previous_node;
        unsigned long int array_index, has_nodes;

        /* Iterate over each array index */
        for (array_index = 0; array_index < ht->size; array_index++)
        {
                has_nodes = 0;
                current_node = (ht->array)[array_index];

                /* Traverse the linked list at the array index */
                while (current_node)
                {
                        has_nodes = 1;
                        previous_node = current_node;
                        current_node = current_node->next;

                        /* Free the key, value, and node */
                        free(previous_node->key);
                        free(previous_node->value);
                        free(previous_node);
                }

                /* Free the array index if it has no nodes */
                if (!has_nodes)
                        free((ht->array)[array_index]);
        }

        /* Free the array and the hash table */
        free(ht->array);
        free(ht);
}


/**
 * shash_table_delete_slist - Deletes the linked list of a sorted hash table and frees the memory
 * @ht: Pointer to the hash table
 */
void shash_table_delete_slist(const shash_table_t *ht)
{
        shash_node_t *current_node, *previous_node;

        /* Check for NULL pointer */
        if (ht == NULL)
                return;

        /* Start from the head of the sorted linked list */
        current_node = ht->shead;
        previous_node = NULL;

        /* Traverse the sorted linked list */
        while (current_node)
        {
                previous_node = current_node;
                current_node = current_node->snext;

                /* Free the key, value, and node */
                free(previous_node->key);
                free(previous_node->value);
                free(previous_node);
        }
}

/**
 * shash_table_delete - Deletes a sorted hash table and frees the memory
 * @ht: Pointer to the hash table
 */
void shash_table_delete(shash_table_t *ht)
{
        /* Delete the linked list */
        shash_table_delete_slist(ht);

        /* Delete the array and the hash table */
        shash_table_delete_arr(ht);
}
