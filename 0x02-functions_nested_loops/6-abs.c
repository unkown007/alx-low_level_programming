#include "main.h"

/**
 * _abs - computs an absolute value of an integer
 * @j: integer number
 *
 * Return: j if j is great than 0, -j if j is less than 0, 0 otherwise
 */
int _abs(int j)
{
	if (j > 0)
		return (j);
	else if (j < 0)
		return (-j);
	else
		return (0);
}
