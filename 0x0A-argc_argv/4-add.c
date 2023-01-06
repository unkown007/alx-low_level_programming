#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - prints the sum of all arguments of program
 * @argv: pointer to an array of char (arguments of the program)
 * @argc: int (number of the argument)
 *
 * Return: 0 (success), 1 otherwise
 */
int main(int argc, char *argv[])
{
	int sum;
	char *tmp;

	if (argc - 1 == 0)
	{
		printf("0\n");
		return (0);
	}

	sum = 0;
	argv++;
	while (*argv)
	{
		tmp = *argv;

		while (*tmp)
		{
			if (!isdigit(*tmp))
			{
				printf("Error\n");
				return (1);
			}
			tmp++;
		}
		sum += atoi(*argv++);
	}

	printf("%d\n", sum);

	return (0);
}
