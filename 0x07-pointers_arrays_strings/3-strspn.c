#include "main.h"
#include <ctype.h>

/**
 * _strchr2 - look for ocurrence of a char in a string
 * @str: char buffer
 * @c: char
 *
 * Return: int;
 */
int _strchr2(char *str, char c)
{
	for (; *str != '\0' && *str != c; str++)
		;

	return (*str == c ? 1 : 0);
}

/**
 * _strspn - gets the length of a prefix substring
 * @s: char buffer
 * @accept: char buffer
 *
 * Return: number of bytes
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;

	while (*s)
	{
		count = 0;

		while (_strchr2(accept, *s) && *s != '\0')
		{
			s++;
			count++;
		}

		if (!isalpha(*s))
			return (count);

		while (!_strchr2(accept, *s) && *s != '\0')
			s++;
	}

	return (0);
}
