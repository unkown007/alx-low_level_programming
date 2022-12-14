#include <stddef.h>
#include "main.h"

/**
 * _strchr - locates a character in a string
 * @s: char buffer
 * @c: char
 *
 * Return: pointer to first occurrence of the character c in the string s
 * or NULL if the character is not found
 */
char *_strchr(char *s, char c)
{
	for (; *s != '\0' && *s != c; s++)
		;

	return (*s == c ? (char *) s : NULL);
}
