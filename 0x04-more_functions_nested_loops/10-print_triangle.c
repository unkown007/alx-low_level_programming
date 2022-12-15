#include "main.h"

/**
 * print_triangle - print triangle of \ with n dimension
 * @size: integer
 */
void print_triangle(int size)
{
	int i, j;

	for (i = size - 1; i >= 0; i--)
	{
		for (j = 0; j < size; j++)
			if (i > j)
				_putchar(' ');
			else
				_putchar('#');
		_putchar('\n');
	}

	if (size <= 0)
		_putchar('\n');
}
