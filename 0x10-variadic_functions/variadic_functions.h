#ifndef VARIADIC_H
#define VARIADIC_H

#include <stdarg.h>

/**
 * struct t - struct t
 * @f: pointer to a function
 * @c: represetation of the type
 */
struct t
{
	char *c;
	void (*f)(va_list, char *);
};
typedef struct t _type;

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

#endif
