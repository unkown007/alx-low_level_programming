#include "main.h"
#include <stdio.h>

/**
 * print_number - print a number independetly of the sign
 * @n: integer
 */
void print_number(int n)
{
	char d[100];
	int aux, tmp;

	tmp = n;
	n = (n < 0) ? -n : n;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	aux = 0;
	while (n > 0)
	{
		d[aux] = (n % 10) + '0';
		aux++;
		n /= 10;
	}

	if (tmp < 0)
		d[aux++] = '-';

	aux--;
	while (aux >= 0)
		_putchar(d[aux--]);
}

/**
 * print_to_98 - prints all natural numbers from n to 98
 * @n: integer
 */
void print_to_98(int n)
{
	int i;

	if (n > 98)
	{
		for (i = n; i >= 98; i--)
		{
			print_number(i);

			if (i > 98)
			{
				_putchar(',');
				_putchar(' ');
			}
		}
	} else
	{
		for (i = n; i <= 98; i++)
		{
			print_number(i);

			if (i < 98)
			{
				_putchar(',');
				_putchar(' ');
			}
		}
	}
	_putchar('\n');
}
