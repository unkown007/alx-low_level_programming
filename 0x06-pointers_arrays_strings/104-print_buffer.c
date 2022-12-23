#include "main.h"
#include <stdio.h>

/**
 * print_buffer - prints a buffer
 * @b: pointer to char
 * @size: int
 */
void print_buffer(char *b, int size)
{
	int count, i, j;

	for (i = 0, count = 0; i < size;)
	{
		printf("%08x: ", count);

		j = i;
		for (j = i; j < (count + 10); j++)
		{
			if (j < size)
				printf("%02x", b[j]);
			else
				printf("  ");
			if (j % 2)
				printf(" ");
		}

		printf(" ");
		for (; i < (count + 10) && i < size; i++)
			if (b[i] >= 32 && b[i] <= 126)
				printf("%c", b[i]);
			else
				printf(".");
		count += 10;
		printf("\n");
	}
}
