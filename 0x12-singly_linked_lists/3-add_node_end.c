#include "lists.h"
/**
 *add_node_end -  a function that adds a new node at the end
 *of a list_t list.
 *@head:a pointer that pointes to a pointer pointing to head.
 *@str: a point to the first element of the string to be stored.
 *Return: the address of the new element, or NULL if it failed.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node;
	list_t *last = *head;
	size_t i;

	if (head == NULL)
		return (NULL);
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);
	new_node->str = strdup(str);
	if (str == NULL)
	{
		free(new_node);
		return (NULL);
	}
	for (i = 0; str[i]; i++)
		;
	new_node->len = i;
	new_node->next = NULL;


	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return (new_node);
}
