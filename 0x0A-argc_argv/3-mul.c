#include <stdio.h>
#include <stdlib.h>

/**
 * main - multiplies two numbers
 * @argv: pointer to an array of char (arguments of the program)
 * @argc: int (number of the argument)
 *
 * Return: 0 (success), 1 otherwise
 */
int main(int  argc, char *argv[])
{
	int n1, n2;

	if (argc - 1 != 2)
	{
		printf("Error\n");
		return (1);
	}

	n1 = atoi(argv[1]);
	n2 = atoi(argv[2]);

	printf("%d\n", n1 * n2);

	return (0);
}
