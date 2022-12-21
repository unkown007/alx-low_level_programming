#include "main.h"

/**
 * reverse_array - reverts the first n elements of the array
 * @a: pointer to int
 * @n: int
 */
void reverse_array(int *a, int n)
{
	int i, j, aux;

	i = 0;
	j = n - 1;
	while (i < j)
	{
		aux = a[i];
		a[i] = a[j];
		a[j] = aux;

		i++;
		j--;
	}
}
