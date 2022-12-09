#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (sucess)
 */
int main(void)
{
	int c;

	for (c = 97; c <= 122; c++)
		if ((c != (int) 'q') && (c != (int) 'e'))
			putchar((char) c);
	putchar('\n');

	return (0);
}
