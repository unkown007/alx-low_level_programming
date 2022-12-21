#include "main.h"

/**
 * _strncat - concatenates two strings
 * @dest: pointer to char
 * @src: pointer to char
 * @n: integer
 *
 * Return: Always dest (addr);
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, count = 0;

	while (dest[i] != '\0')
		i++;

	while (((dest[i] = *src++) != '\0') && (count++ < n))
		i++;

	if (dest[i] != '\0')
		dest[i] = '\0';

	return (dest);
}
