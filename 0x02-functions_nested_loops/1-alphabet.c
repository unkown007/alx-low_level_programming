#include "main.h"

/**
 * print_alphabet - print the alphabet in lowercase
 *
 * Return: Always nothing (void);
 */
void print_alphabet(void)
{
	int i;

	for (i = 97; i <= 122; i++)
		_putchar((char) i);
	_putchar('\n');
}
