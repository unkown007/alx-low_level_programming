#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * main - prints the opcodes of its own main function
 * @argc: number of arguments
 * @argv: arguments
 *
 * Return: 0 (success), or faillure code 1,2
 */
int main(int argc, char *argv[])
{
	int n_bytes, i;
	char *op;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	n_bytes = atoi(argv[1]);
	if (n_bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	op = (char *) main;
	for (i = 0; i < n_bytes - 1; i++)
		printf("%02hhx ", op[i]);
	printf("%02hhx\n", op[i]);

	return (EXIT_SUCCESS);
}
