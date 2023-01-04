#include "main.h"

/**
 * _strlen_recursion - computes the length of a string
 * @s: pointer to char buffer
 *
 * Return: length of a string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return 0;
	return 1 + _strlen_recursion(s+1);
}
