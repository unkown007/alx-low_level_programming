#include "main.h"

/**
 * _isdigit - checks whether a character is a digit or not
 * @s: character
 *
 * Return: 1 if s is digit, otherwise 0
 */
int _isdigit(char s)
{
	return ((s >= 48 && s <= 57) ? 1 : 0);
}

/**
 * _atoi - convert a string in an integer
 * @s: pointer to string
 *
 * Return: integer number
 */
int _atoi(char *s)
{
	int n, flag;

	n = 0;
	flag = 0;

	while (!_isdigit(*s) && *s != '\0')
	{
		if (*s == '-')
			flag = 1;
		s++;
	}

	while (_isdigit(*s) && *s != '\0')
	{
		if (!flag)
			n = n * 10 + (*s - '0');
		else
			n = n * 10 - (*s - '0');
		s++;
	}

	while (!_isdigit(*s) && *s != '\0')
	{
		if ((*s >= 65 && *s <= 90)
			|| (*s >= 97 && *s <= 122))
			flag = 0;
		s++;
	}



	return (flag ? -n : n);
}
