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
 * puts2 - prints every other character of a string,
 * starting with the first character
 * @str: pointer to char
 */
void puts2(char *str)
{
	char n = 0x0a;
	int i;

	for (i = 0; str[i] != '\0'; i++)
		if (i % 2 == 0)
			write(1, &str[i], sizeof(char));
	write(1, &n, sizeof(char));
}
