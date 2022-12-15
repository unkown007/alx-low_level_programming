#include "main.h"

/**
 * _isdigit - checks wether a c is a digit or not
 * @c: integer
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(int c)
{
	return ((c >= 48) && (c <= 57) ? 1 : 0);
}
