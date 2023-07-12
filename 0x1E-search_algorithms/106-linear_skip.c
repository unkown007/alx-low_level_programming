#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 *
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 *
 * Return: pointer to the @value, -1 otherwise
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *low, *high;

	if (list == NULL)
		return (NULL);
	low = list;
	high = list;
	while (high->express && high->n < value)
	{
		low = high;
		high = high->express;
		printf("Value checked at index [%lu] = [%d]\n", high->index, high->n);
		if (high->n >= value)
			break;
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
			low->index, high->index);
	while (low && low->index <= high->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", low->index, low->n);
		if (low->n == value)
			return (low);
		low = low->next;
	}
	return (NULL);
}
