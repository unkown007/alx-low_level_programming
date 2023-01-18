#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * op_add - add two integers numbers
 * @a: first number
 * @b: second number
 *
 * Return: sum of a and b
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - sub two integers numbers
 * @a: first number
 * @b: second number
 *
 * Return: sub of a and b
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - multiply two integers numbers
 * @a: first number
 * @b: second number
 *
 * Return: product of a and b
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - divide two integers numbers
 * @a: first number
 * @b: second number
 *
 * Return: div of a and b
 */
int op_div(int a, int b)
{
	/*if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}*/
	return (a / b);
}

/**
 * op_mod - computes the modulo of two integers numbers
 * @a: first number
 * @b: second number
 *
 * Return: mod of a and b
 */
int op_mod(int a, int b)
{
	/*if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}*/
	return (a % b);
}
