#include "main.h"
#include <stdio.h>

/**
 * print_buffer - prints a buffer
 * @b: pointer to char
 * @size: int
 */
void print_buffer(char *b, int size)
{
	int count, i, j, flag, rem;

	for (i = 0, count = 0; i < size;)
	{
		printf("%08x: ", count);

		j = i;
		flag = i + 2;
		for (j = i, flag = i + 2; j < (count + 10); j++)
		{
			if (j < size)
			{
				if (j == flag)
				{
					printf(" ");
					flag += 2;
				}
				printf("%02x", b[j]);
			}
			else
			{
				rem = ((count + 10) - size) + 2;
				for (; j < (count + 10) + rem; j++)
					printf(" ");
			}
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
