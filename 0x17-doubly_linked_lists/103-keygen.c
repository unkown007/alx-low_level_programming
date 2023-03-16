#include <stdio.h>
#include <stdlib.h>

/**
 * main - generates a password for an user
 * @argc: number of arguments
 * @argv: arguments of the program
 *
 * Return: Always 0
 */
int main(int argc, char __attribute__((unused))*argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: ./keygen5 username\n");
		return (1);
	}
	return (0);
}
