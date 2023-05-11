#include"main.h"
/**
 * _strlen_recursion - returns the length of a string
 * @s: input string
 * Return: always 0.
*/
int _strlen_recursion(char *s)
{
	int c = 0;

	if (*s)
	{
		c++;
		c += _strlen_recursion(s + 1);
	}

	return (c);
}
