#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * coins - compute the minimum numbers of coins for a change
 * @n: int (number)
 * @coin: pointer to int
 * @size: int (size of coin)
 *
 * Return: number of coins
 */
int coins(int n, int *coin, int size)
{
	int i, sum, count;

	sum = count = 0;

	while (sum < n)
	{
		for (i = 0; i < size; i++)
		{
			if ((sum + coin[i]) <= n)
			{
				sum += coin[i];
				count++;
				break;
			}
		}
	}

	return (count);
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
	int  n, coin[] = {25, 10, 5, 2, 1};
	char *tmp;

	if (argc - 1 != 1)
	{
		printf("Error\n");
		return (1);
	}

	tmp = *(argv + 1);

	while (*tmp)
	{
		if (!isdigit(*tmp) && *tmp != '-')
		{
			printf("Error\n");
			return (1);
		}
		tmp++;
	}

	n = atoi(*(argv + 1));
	if (n < 0)
	{
		printf("0\n");
		return (1);
	}

	printf("%d\n", coins(n, coin, 5));

	return (0);
}
