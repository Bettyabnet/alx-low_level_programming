#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints all the elements of a list_t list.
 * @h: the name of the list
 * Description: singly linked list node structure
 * Return: the number of nodes
*/
size_t print_list(const list_t *h)
{
	int x = 0;

	while (h)
	{
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
		printf("[%d] %s\n", h->len, h->str);
		}
		x++;
		h = h->next;
	}
	return (x);
}
