#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "3-calc.h"

/**
 * main - perform simple mathematical operations
 * @argc: number of arguments
 * @argv: arguments
 *
 * Return: Always 0 (success)
 */
int main(int argc, char *argv[])
{
	int n1, n2, res;
	int (*op)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	if (argv[2][1] != '\0')
	{
		printf("Error\n");
		exit(99);
	}
	n1 = atoi(argv[1]);
	n2 = atoi(argv[3]);
	op = get_op_func(argv[2]);
	res = op(n1, n2);
	printf("%d\n", res);

	return (EXIT_SUCCESS);
}
