#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _strdup - Returns a pointer to a newly-allocated space in memory
 * @str: string to copy
 *
 * Return: null if insufficient memory or str == null
*/

char *_strdup(char *str)
{
	unsigned int a, b;
	char *new;

	if (str == NULL)
	{
		return (NULL);
	}
	for (a = 0; str[a]; a++)
		;
	a++;

	new = malloc(a * sizeof(char));

	if (new == NULL)
		return (NULL);
	for (b = 0; b < a; b++)
		new[b] = str[b];

	return (new);
}
