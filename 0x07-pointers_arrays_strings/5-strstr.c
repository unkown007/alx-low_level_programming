#include "main.h"
#include <stddef.h>

/**
 * _strstr - finds a first occurrence of the substring needle
 * in the string haystack
 * @haystack: pointer to buffer
 * @needle: pointer to substring
 *
 * Return: pointer to the beginning of the located substring, or NULL
 */
char *_strstr(char *haystack, char *needle)
{
	char *tmp_1, *tmp_2;

	tmp_1 = haystack;
	while (*tmp_1)
	{
		tmp_2 = needle;
		while (*tmp_1 != *tmp_2 && *tmp_1)
			tmp_1++;

		haystack = tmp_1;
		while (*tmp_1 == *tmp_2 && *tmp_1 && *tmp_2)
		{
			if (*(tmp_1+1) == '\0')
				break;
			tmp_1++;
			tmp_2++;
		}

		if (*(tmp_2+1) == '\0')
			return ((char *) haystack);
	}

	return (NULL);
}
