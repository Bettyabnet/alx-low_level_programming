#include "main.h"
#include <stdio.h>
/**
 * _pow_recursion - pow recursion
 * @x: integer input
 * @y: integer input
 *
 * Return: if y < 0 - return -1 else 0
*/
int _pow_recursion(int x, int y)
{
	if (y < 0)
	{
		return (-1);
	}
	else if (y == 0)
	{
		return (1);
	}
	return (x * _pow_recursion(x, y - 1));
}
