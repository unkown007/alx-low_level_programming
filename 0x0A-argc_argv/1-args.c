#include <stdio.h>

/**
 * main - prints the number of arguments of program
 * @argv: pointer to an array of char (arguments of the program)
 * @argc: int (number of the argument)
 *
 * Return: Always 0 (success)
 */
int main(int argc, char __attribute__((unused)) *argv[])
{
	printf("%d\n", argc - 1);

	return (0);
}
