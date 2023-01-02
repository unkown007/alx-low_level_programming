#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sum of the two diagonals of a square
 * matrix of integers
 * @a: pointer to matrix
 * @size: int size
 */
void print_diagsums(int *a, int size)
{
	int i, diag, j, sum_1, sum_2;

	sum_1 = sum_2 = 0;

	for (i = j = diag = 0; i < size * size; i++, j++)
	{
		if (j == diag)
			sum_1 += (*(a + i));

		if (j == size)
		{
			j = 0;
			diag++;
		}
	}

	for (i = size * size - 1, j = 0, diag = size - 1; i >= 0; i--, j++)
	{
		if (j == size)
		{
			j = 0;
			diag--;
		}

		if (j == diag)
			sum_2 += (*(a + i));
	}

	printf("%d, %d\n", sum_1, sum_2);
}
