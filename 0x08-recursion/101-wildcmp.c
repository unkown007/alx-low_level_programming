#include "main.h"

/**
 * _strlen - computes a string length
 * @s: pointer to char
 *
 * Return: length
 */
int _strlen(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + (_strlen(s + 1)));
}

/**
 * wildcmp - compares two strings
 * @s1: pointer to char
 * @s2: pointer to char
 *
 * Return: 1 if equal, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 != '*')
		if (*s1 != *s2)
			return (0);

	if (*s2 == '*')
	{
		if (*(s2 + 1) == '*')
			return (wildcmp(s1, s2 + 1));

		if (*s1 == '\0' && *(s2 + 1) == '\0')
		{
			return (1);
		}

		if (_strlen(s1) > _strlen(s2))
			return (wildcmp(s1 + 1, s2));

		if (*s1 == *(s2 + 1))
			return (wildcmp(s1, s2 + 1));

		if (*s1 != *(s2 + 1))
			return (wildcmp(s1 + 1, s2));
	}

	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	return (wildcmp(s1 + 1, s2 + 1));
}
