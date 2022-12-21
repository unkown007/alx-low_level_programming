#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: pointer to char
 * @src: pointer to char
 *
 * Return: Always dest (addr);
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;

	while (dest[i] != '\0')
		i++;
	while ((dest[i] = *src++) != '\0')
		i++;

	return (dest);
}
