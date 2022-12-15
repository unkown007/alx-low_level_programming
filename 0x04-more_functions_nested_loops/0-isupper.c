#include "main.h"

/**
 * _isupper - checks wether a c is uppercase or not
 * @c: integer
 *
 * Return: 1 if c is uppercase, 0 otherwise
 */
int _isupper(int c)
{
	return ((c >= 65) && (c <= 90) ? 1 : 0);
}
