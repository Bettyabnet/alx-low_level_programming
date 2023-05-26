#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_strings - function that prints strings
 * @separator: separator
 * @n: count of variables
 * Return: void
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int i;
	char *Str;

	va_start(ap, n);
	for (i = 0; i < n; i++)
	{
		Str = va_arg(ap, char *);
		if (Str != NULL)
			printf("%s", Str);
		else
			printf("%s", "(nil)");

		if (i < (n - 1) && separator != NULL)
			printf("%s", separator);
	}
	printf("\n");
	va_end(ap);
}
