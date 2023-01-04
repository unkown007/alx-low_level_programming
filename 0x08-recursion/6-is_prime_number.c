#include "main.h"

/**
 * check - check is a number is prime
 * @i: int
 * @n: int
 *
 * Return: 1 or 0
 */
int check(int i, int n)
{
	if (i == n)
		return (1);

	if ((n % i) == 0 && i < n)
		return (0);

	return (check(i + 1, n));
}

/**
 * is_prime_number - checks whether a number is prime
 * @n: int
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n < 2)
		return (0);

	return (check(2, n));
}
