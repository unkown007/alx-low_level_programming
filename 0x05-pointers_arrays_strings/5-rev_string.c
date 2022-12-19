#include <stdlib.h>
#include "main.h"

/**
 * _strlen - computes length of a string
 * @s: pointer to char
 *
 * Return: lenth the of a string s;
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s++ != '\0')
		length++;
	return (length);
}

/**
 * rev_string - reverses a string
 * @s: pointer to a char
 */
void rev_string(char *s)
{
	char *tmp = malloc(sizeof(char) * _strlen(s));
	int i;

	for (i = 0; (tmp[i] = s[i]) != '\0'; i++)
		;

	i--;
	for (; i >= 0; i--)
		*s++ = tmp[i];

	free(tmp);
}
