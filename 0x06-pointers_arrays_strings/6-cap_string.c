#include "main.h"

/**
 * is_separator - tests whether c is a separator or not
 * @c: char
 *
 * Return: 1 is c is separator, 0 otherwise
 */
int is_separator(char c)
{
	char *separators = " \t\n,;.!?\"(){}";
	int i;

	for (i = 0; separators[i] != '\0'; i++)
		if (separators[i] == c)
			return (1);
	return (0);
}

/**
 * cap_string - capitalizes all words of a string
 * @str: pointer to char
 *
 * Return: Always str (string capitalized)
 */
char *cap_string(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (!is_separator(str[i]))
		{
			if (str[i] >= 97 && str[i] <= 122)
				str[i] -= 32;
			i++;
			while (!is_separator(str[i]) && str[i] != '\0')
				i++;
		}
	}

	return (str);
}
