#include "main.h"
/**
 * _isalpha - checks wether a c is alphabet or not
 * @c: character
 *
 * Return: 1 if c is alphabet, 0 otherwise
 */
int _isalpha(int c)
{
	return (_isupper(c) || _islower(c));
}

/**
 * _isupper - checks wether a c is uppercase or not
 * @c: character
 *
 * Return: 1 if c is uppercase, 0 otherwise
 */
int _isupper(int c)
{
	return ((c >= 65) && (c <= 90) ? 1 : 0);
}

