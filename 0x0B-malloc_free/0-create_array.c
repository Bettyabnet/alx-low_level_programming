#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * create_array -> creating array
 * @size: size of array to be created
 * @c: character an array is initialized with
 * Return: a pointer to an array
*/
char *create_array(unsigned int size, char c)
{
	unsigned int k;
	char *i;

	if (size == 0)
		return (NULL);

	i = (char *)malloc(size * sizeof(char));
	if (i == NULL)
		return (NULL);
	for (k = 0; k < size; k++)
		i[k] = c;

	return (i);
}
