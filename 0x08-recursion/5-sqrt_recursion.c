#include "main.h"

/**
 * _sqrt - computes the root throw bissession method
 * @root: int
 * @n: int
 *
 * Return: return the root
 */
int _sqrt(int root, int n)
{
	if (root * root == n)
		return (root);
	if (root * root > n)
		return (-1);
	return (_sqrt(root + 1, n));
}

/**
 * _sqrt_recursion - computes a natural square root of a number
 * @n: int
 *
 * Return: if n>=0 square root of n, otherwise -1
 */
int _sqrt_recursion(int n)
{
	if (n == 0)
		return (0);
	return (_sqrt(1, n));
}
