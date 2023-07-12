#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * bs - binary search algorithm
 *
 * @array: pointer to the first element of the array to search in
 * @value: value to search for
 * @low: lower bound of the array
 * @high: higher bound of the array
 *
 * Return: index of the @value, -1 otherwise
 */
int bs(int *array, int value, size_t low, size_t high)
{
	size_t mid, i;

	if (low <= high)
	{
		printf("Searching in array: ");
		for (i = low; i < high; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);
		mid = (low + high) / 2;
		if (array[mid] == value)
			return (mid);
		else if (array[mid] > value)
			return (bs(array, value, low, mid - 1));
		else if (array[mid] < value)
			return (bs(array, value, mid + 1, high));
	}
	return (-1);
}

/**
 * exponential_search - searches for a value in a sorted array of integers
 *
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in @array
 * @value: value to search for
 *
 * Return: index of the @value, -1 otherwise
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound, r;

	if (array == NULL)
		return (-1);
	bound = 1;
	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}
	r = size > bound ? bound : size - 1;
	printf("Value found between indexes [%lu] and [%lu]\n", bound / 2, r);
	return (bs(array, value, bound / 2, r));
}
