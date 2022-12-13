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
 * fibonacci - computes and print the first 50 Fibonacci numbers
 */
void fibonacci(void)
{
	long int a1, a2, an;
	int count;

	count = 2;
	
	a1 = 1;
	print_number(a1);
	_putchar(',');
        _putchar(' ');

	a2 = 2;
	print_number(a2);
	_putchar(',');
	_putchar(' ');

	while (count < 50)
	{
		an = a1 + a2;
		a1 = a2;
		a2 = an;

		print_number(an);
		if (count < 49)
		{
			_putchar(',');
        		_putchar(' ');
		}
		count++;
	}
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
