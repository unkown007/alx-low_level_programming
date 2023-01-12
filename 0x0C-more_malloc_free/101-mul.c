#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

/**
 * print_msg - print msg
 * @str: msg
 */
void print_msg(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		_putchar(str[i]);
	_putchar('\n');
}

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: arguments
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	long n1, n2, result;
	int i, j;
	char *buffer;

	if (argc != 3)
	{
		print_msg("Error");
		exit(98);
	}

	for (i = 0; i < argc; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (argv[i][j] < '0' && argv[i][j] > '9')
			{
				print_msg("Error");
				exit(98);
			}
		}
	}

	n1 = atol(argv[1]);
	n2 = atol(argv[2]);
	result = n1 * n2;
	buffer = malloc(1024 * sizeof(char));
	if (buffer == NULL)
	{
		print_msg("Error");
		exit(98);
	}

	sprintf(buffer, "%ld\0", result);
	print_msg(buffer);

	return (0);
}
