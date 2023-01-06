#include <stdio.h>

/**
 * main - prints the arguments of program
 * @argv: pointer to an array of char (arguments of the program)
 * @argc: int (number of the argument)
 *
 * Return: Always 0 (success)
 */
int main(int __attribute__((unused)) argc, char *argv[])
{
	
	while (*argv)
		printf("%s\n", *argv++);

	return (0);
}
