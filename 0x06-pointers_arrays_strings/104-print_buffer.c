#include "main.h"
#include <stdio.h>

/**
 * line - print line
 * @b: buffer
 * @size: size
 * @l: line
 */
void line(char *b, int size, int l)
{
	int j;

	for (j = 0; j <= 9; j++)
	{
		if (j <= size)
			printf("%02x", b[l * 10 + j]);
		else
			printf("  ");
		if (j % 2)
			putchar(' ');
	}

	for (j = 0; j <= size; j++)
		if (b[l * 10 + j] >= 32 && b[l * 10 + j] <= 126)
			printf("%c", b[l * 10 + j]);
		else
			printf(".");
}


/**
 * print_buffer - prints a buffer
 * @b: pointer to char
 * @size: int
 */
void print_buffer(char *b, int size)
{
	int i, j;

	for (i = 0; i <= (size - 1) / 10 && size; i++)
	{
		printf("%08x: ", i * 10);

		if (i < size / 10)
			line(b, 9, i);
		else
			line(b, size % 10 - 1, i);
		putchar('\n');
	}
	if (size == 0)
		putchar('\n');
}
