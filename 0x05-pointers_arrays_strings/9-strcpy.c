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
	while ((*dest++ = *src++) != '\0')
		;

	return (dest);
}
