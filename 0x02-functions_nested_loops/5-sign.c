#include "main.h"

/**
 * print_sign - prints the sign of any number
 * @n: integer numer
 *
 * Return: 1 if n is greater than zero, -1 if n is less than zero, 0 otherwise
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	} else if (n < 0)
	{
		_putchar('-');
		return (-1);
	}

	_putchar('0');
	return (0);
}
