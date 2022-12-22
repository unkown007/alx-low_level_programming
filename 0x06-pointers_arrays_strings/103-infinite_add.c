#include "main.h"
#include <stdio.h>

/**
 * infinite_add - add two infinit numbers
 * @n1: first number
 * @n2: second number
 * @r: result
 * @size_r: buffer size
 *
 * Return: r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int sum, i, j, size, n;

	for (i = 0; n1[i] != '\0'; i++)
		;
	for (j = 0; n2[j] != '\0'; j++)
		;

	if (i > size_r || j > size_r)
		return (0);

	n = 0;
	for (i -= 1, j -= 1, size = 0; size < size_r; i--, j--, size++)
	{
		sum = n;
		if (i >= 0)
			sum += n1[i] - '0';
		if (j >= 0)
			sum += n2[j] - '0';

		if (i < 0 && j < 0 && n == 0)
			break;
		n = sum / 10;
		r[size] = (sum % 10) + '0';
	}

	if (i >= 0 || j >= 0 || sum)
		return (0);

	for (i = 0, j = size - 1; i < j; i++, j--)
	{
		n = r[i];
		r[i] = r[j];
		r[j] = n;
	}

	return (r);
}
