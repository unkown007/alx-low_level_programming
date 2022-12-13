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
 * print_sum - computes and print the sum of all mutiple of 3 or 5 bellow 1024
 */
void print_sum(void)
{
	int i, sum;

	sum = 0;
	for (i = 0; i < 1024; i++)
	{
		if (((i % 3) == 0) || ((i % 5) == 0))
			sum += i;
	}

	print_number(sum);
	_putchar('\n');
}


/**
 * main - tests the function
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	print_sum();
	return (0);
}
