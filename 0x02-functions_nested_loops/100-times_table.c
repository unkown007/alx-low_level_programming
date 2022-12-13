#include "main.h"

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
 * times_table - prints the 9 times table, starting with 0
 */
void print_times_table(int n)
{
	int i, j, aux;

	if ((n > 15) || (n < 0)) return;

	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			aux = j * i;
			print_number(aux);

			if (j < n)
			{
				_putchar(',');
				if ((i * (j + 1)) >= 100)
				{
					_putchar(' ');
				} else if ((i * (j + 1)) < 10)
				{
					_putchar(' ');
					_putchar(' ');
					_putchar(' ');
				} else
				{
					_putchar(' ');
					_putchar(' ');
				}
			}
		}
		_putchar('\n');
	}
}
