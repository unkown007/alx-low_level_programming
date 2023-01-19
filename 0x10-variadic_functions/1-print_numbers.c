#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_numbers - print numbers followed by a new line
 * @separator: separator of the output
 * @n: number of args passed to the function
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int i;

	if (n == 0)
	{
		putchar('\n');
		return;
	}
	va_start(ap, n);
	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(ap, int));
		if (separator != NULL && i != n - 1)
			printf("%s", separator);
	}
	va_end(ap);
	putchar('\n');
}
