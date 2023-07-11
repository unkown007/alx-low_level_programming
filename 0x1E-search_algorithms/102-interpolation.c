#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * interpolation_search - searches for a value in a sorted array
 *
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in @array
 * @value: value to search for
 *
 * Return: index of the @value, -1 otherwise
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t low, high, pos;

	if (array == NULL)
		return (-1);
	low = 0;
	high = size - 1;
	while ((array[high] != array[low]) && (value >= array[low]) &&
			(value <= array[high]))
	{
		pos = low + (((double)(high - low) / (array[high] - array[low])) *
				(value - array[low]));
		printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);
		if (array[pos] < value)
			low = pos + 1;
		else if (value < array[pos])
			high = pos - 1;
		else
			return (pos);
	}
	pos = low + (((double)(high - low) / (array[high] - array[low])) *
			(value - array[low]));
	if (pos < size)
		printf("Value checked array[%lu] = [%d]\n", low, array[low]);
	else
	{
		printf("Value checked array[%lu] is out of range\n", pos);
		return (-1);
	}
	if (value == array[low])
		return (low);
	return (-1);
}
