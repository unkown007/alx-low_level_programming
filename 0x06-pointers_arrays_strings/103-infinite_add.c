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
	int sum, i, j, size;

	for (i = 0; n1[i] != '\0'; i++)
		;
	for (j = 0; n2[j] != '\0'; j++)
		;

	i--;
	j--;

	sum = 0;
	size = 0;
	while (i >= 0 && j >= 0)
	{
		if (sum)
			sum = ((n1[i] - '0') + (n2[j] - '0')) + 1;
		else
			sum = (n1[i] - '0') + (n2[j] - '0');

		r[size] = (sum % 10) + '0';
		sum /= 10;
		i--;
		j--;
		size++;
	}

	if ( i >= 0)
	{
		while (i >= 0)
		{
			if (sum)
			{
				sum = (n1[i] - '0') + 1;
				r[size] = (sum % 10) + '0';
				sum /= 10;
			}
			else
				r[size] = n1[i];
			i--;
			size++;
		}
	}
	else
	{
		while (j >= 0)
		{
			if (sum)
			{
				sum = (n2[j] - '0') + 1;
				r[size] = (sum % 10) + '0';
				sum /= 10;
			}
			else
				r[size] = n2[j];
			j--;
			size++;
		}
	}

	if (sum)
	{
		r[size++] = '1';
	}

	if (size >= size_r)
		return 0;

	i = 0;
	j = size - 1;

	while (i < j)
	{
		sum = r[i];
		r[i] = r[j];
		r[j] = sum;

		i++;
		j--;
	}

	return (r);
}
