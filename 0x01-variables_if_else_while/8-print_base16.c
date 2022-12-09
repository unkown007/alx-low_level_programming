#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (sucess)
 */
int main(void)
{
	int c;

	for (c = 48; c <= 57; c++)
		putchar(c);

	for (c = 97; c <= 66; c++)
		putchar(c);
	putchar('\n');

	return (0);
}
