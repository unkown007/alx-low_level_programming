#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * coins - compute the minimum numbers of coins for a change
 * @n: int (number)
 *
 * Return: number of coins
 */
int coins(int n)
{
	int c = 0;

	if (n % 25 >= 0)
	{
		c += n / 25;
		n %= 25;
	}
	if (n % 10 >= 0)
	{
		c += n / 10;
		n %= 10;
	}
	if (n % 5 >= 0)
	{
		c += n / 5;
		n %= 5;
	}
	if (n % 2 >= 0)
	{
		c += n / 2;
		n %= 2;
	}
	if (n % 1 >= 0)
	{
		c += n / 1;
		n %= 1;
	}

	return (c);
}

/**
 * main - prints the minimum number of coins to make change for
 * an amount of money
 * @argv: pointer to an array of char (arguments of the program)
 * @argc: int (number of the argument)
 *
 * Return: 0 (success), 1 otherwise
 */
int main(int argc, char *argv[])
{
	int  n;

	if (argc - 1 != 1)
	{
		printf("Error\n");
		return (1);
	}

	n = atoi(*(argv + 1));
	if (n < 0)
	{
		printf("0\n");
		return (1);
	}

	printf("%d\n", coins(n));

	return (0);
}
