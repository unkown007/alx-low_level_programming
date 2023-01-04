#include "main.h"

/**
 * _pow_recursion - computes the power of a number
 * @x: int
 * @y: int
 *
 * Return: if y >= 0 x power of y, otherwise -1
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	return (x * _pow_recursion(x, y - 1));
}
