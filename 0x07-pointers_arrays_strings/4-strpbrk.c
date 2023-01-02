#include "main.h"
#include <stddef.h>

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

	return (*str == c);
}


/**
 * _strpbrk - locates the first occurrence in the string s of any
 * of the bytes in the string accept
 * @s: pointer to char buffer
 * @accept: pointer to char bytes
 *
 * Return: a ponter to the bytes in s, or NULL
 */
char *_strpbrk(char *s, char *accept)
{
	for (; *s && !_strchr2(accept, *s); s++)
		;

	return (_strchr2(accept, *s) ? (char *) s : NULL);
}
