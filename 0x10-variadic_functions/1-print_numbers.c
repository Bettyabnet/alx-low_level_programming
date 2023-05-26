#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_numbers - function that prints numbers ffl by a new line
 * @separator: separating string
 * @n: count of arguments
 * Return: void
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list ap;

	va_start(ap, n);
	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(ap, int));
		if (separator != NULL && i < (n - 1))
			printf("%s", separator);
	}
	printf("\n");
	va_end(ap);

}
