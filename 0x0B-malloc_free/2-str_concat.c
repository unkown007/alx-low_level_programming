#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * str_concat - concatenates two strings
 * @s1: pointer to a string
 * @s2: pointer to a string
 *
 * Return: pointer to a newly allocated space in memory, which
 * contains the content of s1, follwed by the content of s2,
 * or NULL in case of failure
 */
char *str_concat(char *s1, char *s2)
{
	unsigned int i;
	char *tmp;

	if (s1 == NULL && s2 == NULL)
		return (NULL);

	tmp = (char *) malloc((strlen(s1) + strlen(s2)) + 1);

	i = 0;
	while (*s1)
		tmp[i++] = *s1++;
	while (*s2)
		tmp[i++] = *s2++;
	tmp[i] = '\0';

	return ((char *) tmp);
}
