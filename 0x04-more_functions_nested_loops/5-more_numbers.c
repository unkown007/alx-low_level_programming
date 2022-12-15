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
 * more_numbers - print numbers from 0 to 14, 10 times
 */
void more_numbers(void)
{
	int i, j;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j <= 14; j++)
			print_number(j);
		_putchar('\n');
	}
}
