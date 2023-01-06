#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
	int i, sum, n, count, coins[] = {25, 10, 5, 2, 1};

	if (argc - 1 != 1)
	{
		printf("Error\n");
		return (1);
	}

	sum = 0;
	n = atoi(*(argv + 1));

	if (n < 0)
	{
		printf("0\n");
		return (0);
	}

	count = 0;
	while (sum < n)
	{
		for (i = 0; i < 5; i++)
		{
			if ((sum + coins[i]) <= n)
			{
				sum += coins[i];
				count++;
				break;
			}
		}
	}

	printf("%d\n", count);

	return (0);
}
