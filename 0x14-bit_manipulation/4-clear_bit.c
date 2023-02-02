#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given indiex
 * @n: pointer to the number
 * @index: index starting from 0 of the bit
 *
 * Return: 1 if it worked, or -1 if an error occured
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > (8 * sizeof(*n)))
		return (-1);
	*n &= ~(1 << index);
	return (1);
}
