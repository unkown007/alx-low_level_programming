#include "main.h"

void print_alphabet(void);

/**
 * main - Entry point
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	print_alphabet();
	return (0);
}

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
