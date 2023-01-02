#include "main.h"

/**
 * _memcpy - copies n bytes from memory are src to memery area dest
 * @dest: char buffer
 * @src: char buffer
 * @n: int
 *
 * Return: ponter to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n && src[i]; i++)
		dest[i] = src[i];
	
	if (!src[i])
		dest[i] = '\0';

	return (dest);
}
