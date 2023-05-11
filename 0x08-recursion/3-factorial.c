#include"main.h"

/*
 * int factorial - returns a factorial of a given number
 *
 * return: always zero
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
