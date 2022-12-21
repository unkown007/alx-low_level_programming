#include "main.h"

/**
 * string_toupper - convert all lowercase character to uppercase
 * @str: pointer to str
 *
 * Return: Always str in uppercase
 */
char *string_toupper(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		if (str[i] >= 97 && str[i] <= 122)
			str[i] -= 32;
	return (str);
}
