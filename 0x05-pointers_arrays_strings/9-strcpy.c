#include "main.h"

/**
 * _strcpy - copies the string pointed to by src to
 * buffer pointed to by dest
 * @dest: pointer to char
 * @src: pointer to dest
 *
 * Return: pointer do the buffer dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while ((dest[i] = src[i]) != '\0')
		i++;

	return (dest);
}
