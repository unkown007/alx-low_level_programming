#include "main.h"

/**
 * factorial - computes a factorial of a given number n
 * @n: integer
 *
 * Return: if n>=0 factorial of n, otherwise -1
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (1);
	return n*factorial(n-1);
}
