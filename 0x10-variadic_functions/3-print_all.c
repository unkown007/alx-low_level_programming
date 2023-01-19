#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_i - function that print int
 * @list: list of arguments
 * @sep: separator
 */
void print_i(va_list list, char *sep)
{
	printf("%s%d", sep, va_arg(list, int));
}

/**
 * print_c - function that print char
 * @list: list of arguments
 * @sep: separator
 */
void print_c(va_list list, char *sep)
{
	printf("%s%c", sep, va_arg(list, int));
}

/**
 * print_f - function that print float
 * @list: list of arguments
 * @sep: separator
 */
void print_f(va_list list, char *sep)
{
	printf("%s%f", sep, va_arg(list, double));
}

/**
 * print_s - function that print string
 * @list: list of arguments
 * @sep: separator
 */
void print_s(va_list list, char *sep)
{
	char *str;

	str = va_arg(list, char *);
	if (str == NULL)
		str = "(nil)";
	printf("%s%s", sep, str);
}

/**
 * print_all - prints anything
 * @format: format of the output
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	char *separator;
	_type l[] = {
		{"c", print_c},
		{"i", print_i},
		{"f", print_f},
		{"s", print_s},
		{NULL, NULL}
	};
	int i, j;

	va_start(ap, format);
	i = 0;
	separator = "";
	while (format[i] != '\0' && format != NULL)
	{
		j = 0;
		while (j < 4)
		{
			if (format[i] == *(l[j]).c)
			{
				l[j].f(ap, separator);
				separator = ", ";
			}
			j++;
		}
		i++;
	}
	putchar('\n');
	va_end(ap);
}
