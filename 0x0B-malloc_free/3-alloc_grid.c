#include <stdlib.h>
#include "main.h"

/**
 * alloc_grid - create a 2 dimensional array of integers
 * @width: length of x dimension
 * @height: length of y dimension
 *
 * Return: pointer of a pointer to int
 */
int **alloc_grid(int width, int height)
{
	int **tmp, i, j, flag;

	if (width <= 0 || height <= 0)
		return (NULL);

	tmp = malloc(height * sizeof(int *));
	if (tmp == NULL)
	{
		free(tmp);
		return (NULL);
	}

	for (i = 0; i < height; i++)
	{
		tmp[i] = (int *) malloc(width * sizeof(int));
		if (tmp[i] == NULL)
		{
			free(tmp);
			return (NULL);
		}
	}

	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			tmp[i][j] = 0;

	return ((int **) tmp);
}
