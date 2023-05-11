#include"main.h"

/*
 * factorial - returns a factorial of a given number
 * @n: number to return a value
 *
 * return: factorial of n
*/

int factorial(int n)
{
	if (n < 0)
		return (-1);
	else if  (n == 0)
		return (1);

	{
		return (n * factorial(n - 1));
	}
	_putchar ('\n');
}
