#include "main.h"

/**
 * leet - encondes a string into 1337
 * @str: pointer to char
 *
 * Return: str encoded
 */
char *leet(char *str)
{
	char symbols[][2] = {{'A', '4'}, {'E', '3'}, {'O', '0'},
				{'T', '7'}, {'L', '1'}};
	int i, j;

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if ((str[i] == symbols[j][0]) || (str[i] == (symbols[j][0] + 32)))
			{
				str[i] = symbols[j][1];
				break;
			}
		}
	}

	return (str);
}
