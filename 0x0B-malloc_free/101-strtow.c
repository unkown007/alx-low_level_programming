#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * count - count number of words of a string
 * @str: string
 *
 * Return: number of words
 */
int count(char *str)
{
	int i, n = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == ' ')
		{
			if (str[i + 1] != ' ' && str[i + 1] != '\0')
				n++;
		}
		else if (i == 0)
			n++;
	}
	n++;
	return (n);
}

/**
 * strtow - splits a string into words
 * @str: string
 *
 * Return: array of words
 */
char **strtow(char *str)
{
	char **tmp;
	int i, j, k, l, n = 0, w = 0;

	if (str == NULL || *str == '\0')
		return (NULL);
	n = count(str);
	if (n == 1)
		return (NULL);
	tmp = (char **) malloc(n * sizeof(char *));
	if (tmp == NULL)
		return (NULL);
	tmp[n - 1] = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
		{
			for (j = 1; str[i + j] != ' ' && str[i + j]; j++)
				;
			j++;
			tmp[w] = (char *) malloc(j * sizeof(char));
			j--;
			if (tmp[w] == NULL)
			{
				for (k = 0; k < w; k++)
					free(tmp[k]);
				free(tmp[n - 1]);
				free(tmp);
				return (NULL);
			}
			for (l = 0; l < j; l++)
				tmp[w][l] = str[i + l];
			tmp[w][l] = '\0';
			w++;
			i += j;
		}
		else
			i++;
	}
	return (tmp);
}
