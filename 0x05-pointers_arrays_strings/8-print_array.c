#include <stdio.h>
#include "main.h"

/**
 * print_array - print n elements of an array of integers
 * followed by a newline
 * @a: pointer to array of integers
 * @n: integer number of elements
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d", a[i]);
		if (i != n - 1)
			printf(", ");
	}
	putchar('\n');
}
