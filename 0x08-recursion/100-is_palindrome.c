#include "main.h"
#include <stdio.h>

/**
 * get_last - gets last char
 * @s: pointer to string
 *
 * Return: last char
 */
char *get_last(char *s)
{
	if (*s == '\0')
		return ((char *)(s - 1));
	return (get_last(s + 1));
}

/**
 * check - checks if a string is palindrome
 * @i: pointer to char
 * @j: pointer to char
 *
 * Return: 1 or 0
 */
int check(char *i, char *j)
{
	if (i > j)
		return (1);
	if (*i != *j)
		return (0);
	return (check(i + 1, j - 1));
}

/**
 * is_palindrome - checks wether a string is palindrome
 * @s: pointer to char buffer
 *
 * Return: 1 or 0
 */
int is_palindrome(char *s)
{
	if (*s == '\0')
		return (1);
	return (check(s, get_last(s)));
}
