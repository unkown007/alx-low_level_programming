#include "main.h"

/**
 * print_nzero - print numbers non terminated by zero
 * @n: integer
 */
void print_nzero(int n)
{
	int aux;

	aux = 0;

	while (n > 0)
	{
		aux = (aux * 10) + (n % 10);
		n /= 10;
	}

	while (aux > 0)
	{
		_putchar((aux % 10) + '0');
		aux /= 10;
	}
}

/**
 * print_zero - print numbers 0 terminated
 * @n: integer
 */
void print_zero(int n)
{
	int aux, nZero;

	nZero = 0;
	aux = 10;

	while (n % aux == 0)
	{
		nZero++;
		aux *= 10;
	}

	aux /= 10;
	n /= aux;

	print_nzero(n);

	for (aux = 0; aux < nZero; aux++)
		_putchar('0');
}

/**
 * print_number - print a number independetly of the signal
 * @n: integer
 */
void print_number(int n)
{
	int tmp, aux, nZero;

	tmp = (n < 0) ? -n : n;

	if (n > 0)
	{
		if (tmp % 10 != 0)
		{
			print_nzero(tmp);
		}
		else
		{
			print_zero(tmp);
		}
	}
	else if (n < 0)
	{
		_putchar('-');
		if (tmp % 10 != 0)
		{
			print_nzero(tmp);
		}
		else
		{
			print_zero(tmp);
		}
	}
	else
		_putchar('0');
}
