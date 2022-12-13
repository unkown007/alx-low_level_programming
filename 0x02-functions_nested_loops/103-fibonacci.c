#include "main.h"

/**
 * print_number - print a number independetly of the sign
 * @n: integer
 */
void print_number(long n)
{
	char d[100];
	long aux, tmp;

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
 * fibonacci - computes and print the sum of fibonacci values that don't exceed
 * 4000000
 */
void fibonacci(void)
{
	long int a1, a2, an, sum;

	sum = 0;

	a1 = 1;
	a2 = 2;
	sum = a2 + a1;

	while (an < 4000000)
	{
		an = a1 + a2;
		a1 = a2;
		a2 = an;

		sum += an;
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
	fibonacci();
	return (0);
}
