#include "main.h"

/**
 * print_last_digit -  computs and print the last digit of a number
 * @n: an integer number
 *
 * Return: Last digit of a number
 */
int print_last_digit(int n)
{
	int lastDigit;

	lastDigit = n % 10;

	_putchar(lastDigit + '0');
	return (lastDigit);
}
