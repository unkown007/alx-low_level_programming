#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: arguments
 *
 * Return: 0
int main(int argc, char **argv)
{
	long n1, n2;
	int i, j;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	for (i = 0; i < argc; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (argv[i][j] < '0' && argv[i][j] > '9')
			{
				printf("%d - %d Error\n", i, j);
				exit(98);
			}
		}
	}

	n1 = atol(argv[1]);
	n2 = atol(argv[2]);

	printf("%ld\n", n1 * n2);

	return (0);
}
