#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * bs - binary search
 *
 * @array: pointer to the first element of the array to search in
 * @value: value to search
 * @beg: begining of the array
 * @end: ending of the array
 *
 * Return: index of @value, -1 otherwise
 */
int bs(int *array, int value, size_t beg, size_t end)
{
	size_t mid, i;

	if (beg <= end)
	{
		printf("Searching in array: ");
		for (i = beg; i <= end; i++)
		{
			printf("%d", array[i]);
			if (i != end)
				printf(", ");
			else
				printf("\n");
		}
		mid  = (end + beg) / 2;
		if (array[mid] == value && (mid == beg || array[mid - 1] != value))
			return (mid);
		else if (array[mid] < value)
			return (bs(array, value, mid + 1, end));
		else if (array[mid] >= value)
			return (bs(array, value, beg, mid));
	}
	return (-1);
}

/**
 * advanced_binary - searches for a value in a sorted array of integers using
 * binary search algorithm
 *
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in @array
 * @value: value to search for
 *
 * Return: index where @value is located, -1 otherwise
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);
	return (bs(array, value, 0, size - 1));
}
