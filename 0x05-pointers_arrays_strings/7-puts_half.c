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
 * puts_half - prints half of a string followed by a new line
 * @str: pointer to char
 */
void puts_half(char *str)
{
	char nl = 0x0a;
	int i, n, len;

	len = _strlen(str);
	n = (len % 2 != 0 ? (len - 1) / 2
			: len / 2);

	for (i = 0; i < (len - n); i++)
		str++;
	write(1, str, n);
	write(1, &nl, sizeof(char));
}
