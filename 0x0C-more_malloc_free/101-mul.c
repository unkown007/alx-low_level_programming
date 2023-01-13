#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

/**
 * print_msg - print msg
 * @str: msg
 */
void print_msg(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		_putchar(str[i]);
	_putchar('\n');
}

/**
 * check - check for existence of non digit char in an array of string
 * @argc: number of strings
 * @argv: array of strings
 *
 * Return: 1 if non digit is present, 0 otherwise
 */
int check(int argc, char **argv)
{
	int i, j;

	for (i = 0; i < argc; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (argv[i][j] < '0' && argv[i][j] > '9')
			{
				return (1);
			}
		}
	}
	return (0);
}

/**
 * mult - multiplies a string of digit with one digit
 * and stores in buffer
 * @buffer: pointer to the buffer
 * @str: a string of digit
 * @digit: character digit
 */
void mult(char *buffer, char *str, char digit)
{
	int result = 0, d, i, j = 0;

	d = digit - '0';
	for (i = strlen(str) - 1; i >= 0; i--)
	{
		result = (str[i] - '0') * d + (result / 10);
		buffer[j++] = (result % 10) + '0';
	}
	if ((result / 10) > 0)
		buffer[j++] = (result / 10) + '0';
	buffer[j] = '\0';
}

/**
 * _add - add two digit strings
 * @s1: first string
 * @s2: second string
 * @pos: starting pos to sum
 */
void _add(char *s1, char *s2, int pos)
{
	int i, r = 0, j = 0;

	for (i = 0; s2[j]; i++)
	{
		if (i >= pos)
		{
			r = ((s1[i] - '0') + (s2[j] - '0')) + (r / 10);
			s1[i] = (r % 10) + '0';
			j++;
		}
	}
	if ((r / 10) > 0)
		s1[i] = (r / 10) + '0';
	s1[i + 1] = '\0';
}

/**
 * rev - reverts the string
 * @beg: pointer to the begining
 * @end: pointer to the end
 */
void rev(char *beg, char *end)
{
	char aux;

	if (end < beg)
		return;
	aux = *beg;
	*beg = *end;
	*end = aux;
	rev(beg + 1, end - 1);
}

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: arguments
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	int i, j, size_1, size_2, size, tot_size;
	char *buffer, *tmp;

	if (argc != 3 || check(argc, argv))
	{
		print_msg("Error");
		exit(98);
	}

	for (size_1 = 0; argv[1][size_1]; size_1++)
		;
	for (size_2 = 0; argv[2][size_2]; size_2++)
		;

	if (size_1 > size_2)
		size = size_1;
	else
		size = size_2;
	tmp = malloc((size + 1) * sizeof(char));
	if (tmp == NULL)
	{
		print_msg("Error");
		exit(98);
	}
	tot_size = (size_1 * size_2) + 1;
	buffer = malloc(tot_size * sizeof(char));
	if (buffer == NULL)
	{
		print_msg("Error");
		exit(98);
	}
	memset(buffer, '0', tot_size);

	if (strlen(argv[1]) > strlen(argv[2]))
	{
		for (i = strlen(argv[2]) - 1, j = 0; i >= 0; i--, j++)
		{
			mult(tmp, argv[1], argv[2][i]);
			_add(buffer, tmp, j);
		}
	} else
	{
		for (i = strlen(argv[1]) - 1, j = 0; i >= 0; i--, j++)
		{
			mult(tmp, argv[2], argv[1][i]);
			_add(buffer, tmp, j);
		}
	}
	rev(buffer, buffer + strlen(buffer) - 1);
	print_msg(buffer);
	free(buffer);
	free(tmp);

	return (0);
}
