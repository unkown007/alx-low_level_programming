#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * argstostr - concatenates all the arguments passed to the program
 * @ac: number of arguments
 * @av: arguments
 *
 * Return: pointer to all concatenated args or NULL
 */
char *argstostr(int ac, char **av)
{
	int len, i, j, k;
	char *tmp;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 1, len = 0; i < ac; i++)
		for (j = 0; av[i][j] != '\0'; j++)
			len++;
	len += (1 + ac);

	tmp = (char *) malloc(sizeof(char) * len);
	if (tmp == NULL)
	{
		free(tmp);
		return (NULL);
	}

	for (i = k = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			tmp[k++] = av[i][j];
		}
		tmp[k++] = '\n';
	}
	tmp[k++] = '\0';

	return ((char *) tmp);
}
