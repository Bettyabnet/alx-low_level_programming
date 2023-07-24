#include "main.h"
/**
 * _strcmp - compare string values
 * @s1: input value
 * @s2: input value
 *
 * Return: s1[comp] - s2[comp]
*/
int _strcmp(char *s1, char *s2)
{
	int comp;

	comp = 0;
	while (s1[comp] != '\0' && s2[comp] != '\0')
	{
		if (s1[comp] != s2[comp])
		{
			return (s1[comp] - s2[comp]);
		}
		comp++;
	}
	return (0);
}
