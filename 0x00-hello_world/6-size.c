#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (sucess)
 */
int main(void)
{
	printf("Size of a char: %ld byte(s)\n"
		"Size of an int: %ld byte(s)\n"
		"Size of a long int: %ld byte(s)\n"
		"Size of a long long int: %ld byte(s)\n"
		"Size of a float: %ld byte(s)\n",
		sizeof(char),
		sizeof(int),
		sizeof(long),
		sizeof(long long),
		sizeof(float));
	return (0);
}
