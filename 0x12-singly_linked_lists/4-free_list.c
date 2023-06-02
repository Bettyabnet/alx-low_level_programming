#include "lists.h"
/**
 *free_list - a function that frees a linked list.
 *@head: a pointer that pointes the head of the linked list.
 *Return: void.
 */
void free_list(list_t *head)
{
	while (head != NULL)
	{
		if (head->str != NULL)
			free(head->str);
		free(head);
		head = head->next;
	}
}
