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
	char *tmp;

	n = 0;
	flag = 0;
	tmp = s;

	while (!_isdigit(*s) && *s != '\0')
		s++;

	if (*(s - 1) == '-' && (s - 1) >= tmp)
	{
		if ((s - 1) == tmp)
			flag = 1;
		else if (*(s - 2) == '-')
			flag = 1;
	}

	while (_isdigit(*s) && *s != '\0')
	{
		n = n * 10 + (*s - '0');
		s++;
	}

	return (flag ? -n : n);
}
