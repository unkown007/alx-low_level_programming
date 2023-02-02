#include "main.h"

/**
 * count - count the number of active bits
 * @n: unsigned long int number
 *
 * Return: number of active bits
 */
unsigned int count(unsigned long int n)
{
	if (n == 0)
		return (0);
	return ((n & 1) + count(n >> 1));
}

/**
 * flip_bits - computes the number of bits you would need to fleep to get
 * from one number to another
 * @n: first unsigned long integer number
 * @m: second unsigned long integer number
 *
 * Return: number of bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	if (n == m)
		return (0);
	n ^= m;
	return (count(n));
}
