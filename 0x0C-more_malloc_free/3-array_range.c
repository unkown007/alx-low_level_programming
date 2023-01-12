#include <stdlib.h>
#include <time.h>
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
	int *arr, i, j, size, aux;

	if (min > max)
		return (NULL);

	size = abs(max - min + 1);
	arr = malloc(size * sizeof(int));
	if (arr == NULL)
		return (NULL);

	srand((unsigned) time(NULL));
	for (i = 0; i < size; i++)
		arr[i] = min + (rand() % (size));

	for (i = 1; i < size; i++)
	{
		for (j = 0; j < size - i; j++)
		{
			if (arr[j] > arr[j + 1]){
				aux = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = aux;
			}
		}
	}

	return (arr);
}
