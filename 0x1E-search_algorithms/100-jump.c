#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - search for a value in a sorted array of integers using
 * Jump search algorithm
 *
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in @array
 * @value: value to search for
 *
 * Return: index of the @value, -1 otherwise
 */
int jump_search(int *array, size_t size, int value)
{
	size_t i, m;

	if (array == NULL)
		return (-1);
	i = 0;
	m = sqrt(size);
	while (array[i] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (m >= size || array[m] >= value)
			break;
		i = m;
		m = m + sqrt(size);
	}
	printf("Value found between indexes [%lu] and [%lu]\n", i, m);
	while (i < size)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
		i++;
	}
	return (-1);
}
