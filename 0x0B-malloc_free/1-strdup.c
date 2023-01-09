#include <string.h>
#include <stdlib.h>
#include "main.h"

/**
 * _strdup - return a pointer to a newly allocated space in memory
 * which contains a copy of the string given as a parameter
 * @str: pointer to the string
 *
 * Return: pointer to newly allocated space in memory
 */
char *_strdup(char *str)
{
	unsigned int i;
	char *tmp;

	if (str == NULL)
		return (NULL);

	tmp = malloc(strlen(str) + 1);

	if (tmp == NULL)
		return (NULL);

	for (i = 0; (tmp[i] = str[i]) != '\0'; i++)
		;

	return ((char *) tmp);
}
