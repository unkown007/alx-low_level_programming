#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes to get from n
 *
 * Return: concatenated string or NULL if it fails
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *str;
	int i = 0, j;

	if (s1 != NULL && s2 != NULL)
		str = malloc((strlen(s1) + n + 1) * sizeof(char));
	else if (s1 != NULL)
		str = malloc((strlen(s1) + 1) * sizeof(char));
	else if (s2 != NULL)
		if (n >= strlen(s2))
			str = malloc((strlen(s2) + 1) * sizeof(char));
		else
			str = malloc((n + 1) * sizeof(char));
	else
		str = malloc(1 * sizeof(char));

	if (str == NULL)
		return (NULL);

	if (s1 != NULL && s2 != NULL)
	{
		for (j = 0; s1[j]; j++)
			str[i++] = s1[j];
		for (j = 0; s2[j] && j < n; j++, i++)
			str[i] = s2[j];
	} else if (s2 != NULL)
	{
		for (j = 0; s2[j] && j < n; j++, i++)
			str[i] = s2[j];
	} else if (s1 != NULL)
	{
		for (j = 0; s1[j]; j++, i++)
			str[i] = s1[j];
	}
	str[i] = '\0';

	return (str);
}
