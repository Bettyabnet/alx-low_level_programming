#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * sum_them_all - function that returns sum of its parameters
 * @n: first parameter passed
 * Return: int value
 */

int sum_them_all(const unsigned int n, ...)
{
	int sum;
	unsigned int i;
	va_list ap;

	if (n == 0)
		return (0);
	va_start(ap, n);

	sum = 0;
	for (i = 0; i < n; i++)
		sum += va_arg(ap, unsigned int);
	va_end(ap);

	return (sum);
}
