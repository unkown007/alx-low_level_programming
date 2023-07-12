#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_list - searches for a value in a sorted list of integers
 *
 * @list: pointer to the head of the list to search in
 * @size: number of nodes in @list
 * @value: value to search for
 *
 * Return: pointer to the @value node, NULL otherwise
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t m;
	listint_t *low, *high;

	if (list == NULL)
		return (NULL);
	m = sqrt(size);
	low = list;
	high = list;
	while (high->n < value)
	{
		low = high;
		while (high->next && high->index < m)
			high = high->next;
		printf("Value checked at index [%lu] = [%d]\n", high->index, high->n);
		if (m >= size || high->n >= value)
			break;
		m = m + sqrt(size);
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
