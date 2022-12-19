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
 * _puts - writes the string s and a trailing newline to stdout
 * @str: pointer to char
 */
void _puts(char *str)
{
	char n = 0x0a;

	write(1, str, _strlen(str));
	write(1, &n, sizeof(char));
}
