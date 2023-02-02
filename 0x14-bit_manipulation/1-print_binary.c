#include "main.h"

/**
 * _binary - print the binary representation of a number
 * @n: long integer number
 */
void _binary(unsigned long int n)
{
	if (n == 0)
		return;
	_binary(n >> 1);
	_putchar((n & 1) + '0');
}

/**
 * print_binary - prints the binary representation of a number
 * @n: long integer number
 */
void print_binary(unsigned long int n)
{
	if (n == 0)
		_putchar('0');
	else
		_binary(n);
}
