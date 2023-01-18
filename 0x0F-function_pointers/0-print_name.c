#include <stdlib.h>
#include "function_pointers.h"

/**
 * print_name - prints a name
 * @name: array of characters to print
 * @f: pointer to a function that receives a @name as parameter
 */
void print_name(char *name, void (*f)(char *))
{
	if (f == NULL)
		return;
	(*f)(name);
}
