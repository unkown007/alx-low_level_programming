#include <stdio.h>

/**
 * prime - checks whether a number is prime or not
 * @n: long;
 *
 * Return: 1 if n is prime, 0 istead
 */
int prime(long n)
{
	long i;

	for (i = 2; i < n; i++)
	{
		if (n % i == 0)
			return (0);
	}

	return (1);
}

/**
 * main - fizz-buzz test
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	unsigned long n, i;

	n = 612852475143l;

	i = 2;
	while (1)
	{
		if (prime(i))
		{
			if (n % i == 0)
			{
				n /= i;
				if (prime(n))
				{
					printf("%lu\n", n);
					break;
				}
				else
					i = 2;
			}
			else
				i++;
		}
		else
			i++;
	}

	return (0);
}
