#include "main.h"

/**
 * _strncpy - copy n most character from the src to dest
 * @dest: pointer to char
 * @src: pointer to char
 * @n: integer
 *
 * Return: Always dest (addr)
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for ( ; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
