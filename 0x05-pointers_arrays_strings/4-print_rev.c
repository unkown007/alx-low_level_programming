#include <unistd.h>
#include "main.h"

/**
 * _strlen - computes length of a string
 * @s: pointer to char
 *
 * Return: lenth the of a string s;
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s++ != '\0')
		length++;
	return (length);
}

/**
 * print_rev - print a string in reverse, followed by a new line
 * @s: pointer to char
 */
void print_rev(char *s)
{
	int i;
	char n = 0x0a;

	for (i = _strlen(s); i >= 0; i--)
		write(1, &s[i], sizeof(char));
	write(1, &n, sizeof(char));
}
