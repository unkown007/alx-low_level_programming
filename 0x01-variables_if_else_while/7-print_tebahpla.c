#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (sucess)
 */
int main(void)
{
	int c;

	for (c = 122; c >= 97; c--)
		putchar((char) c);
	putchar('\n');

	return (0);
}
