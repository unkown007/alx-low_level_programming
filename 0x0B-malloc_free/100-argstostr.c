#include <stdlib.h>
#include <string.h>
#include "main.h"
#include <stdio.h>

/**
 * argstostr - concatenates all the arguments passed to the program
 * @ac: number of arguments
 * @av: arguments
 *
 * Return: pointer to all concatenated args or NULL
 */
char *argstostr(int ac, char **av)
{
	int len = 0, i, j, k = 0;
	char *tmp;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			len++;
		len++;
	}
	len++;

	tmp = (char *) malloc(len * sizeof(char));
	if (tmp == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			tmp[k] = av[i][j];
			k++;
		}
		tmp[k] = '\n';
		k++;
	}
	tmp[k] = '\0';

	return ((char *) tmp);
}
