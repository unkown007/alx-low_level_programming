#include <stdlib.h>
#include <math.h>
#include "main.h"

/**
 * array_range - create an array of integers
 * @min: minimum number of the array
 * @max: maximum number of the array
 *
 * Return: pointer to the array or NULL
 */
int *array_range(int min, int max)
{
	int *arr, i, size;

	if (min > max)
		return (NULL);

	size = abs(max - min + 1);
	arr = malloc(size * sizeof(int));
	if (arr == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		arr[i] = min + i;

	return (arr);
}
