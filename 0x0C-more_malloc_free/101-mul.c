#include <stdlib.h>
#include "main.h"

/**
 * print_msg - print msg
 * @str: msg
 * @l: size
 */
void print_msg(char *str, int l)
{
	int i, flag = 0;

	for (i = 0; i < l; i++)
	{
		if (str[i] != '0')
			flag = 1;
		if (flag || i == l - 1)
			_putchar(str[i]);
	}
	_putchar('\n');
	free(str);
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
		for (j = 0; argv[i][j] != '\0'; j++)
			if (argv[i][j] < '0' && argv[i][j] > '9')
				return (1);
	return (0);
}

/**
 * init - inicialize an allocated memory
 * @mem: memory to inicialize
 * @l: length of the memory
 */
void init(char *mem, int l)
{
	int i;

	for (i = 0; i < l; i++)
		mem[i] = '0';
	mem[i] = '\0';
}

/**
 * mult - multiplies a string of digit with one digit
 * and stores in buffer
 * @buffer: pointer to the buffer
 * @num:  number
 * @digit: character digit
 * @num_index: last index of the number
 * @buff_index: destiny index
 *
 * Return: 1 success, 0 otherwise
 */
int mult(char *buffer, int buff_index, char *num, int num_index, char digit)
{
	int addrem, mulrem, add, mul, i, j;

	addrem = mulrem = 0;
	for (i = num_index, j = buff_index - 2; i >= 0; i--, j--)
	{
		mul = (digit - '0') * (num[i] - '0') + mulrem;
		mulrem = mul / 10;
		add = (buffer[j] - '0') + (mul % 10) + addrem;
		addrem = add / 10;
		buffer[j] = (add % 10) + '0';
	}
	for (addrem += mulrem; j >= 0 && addrem; j--)
	{
		add = (buffer[j] - '0') + addrem;
		addrem = add / 10;
		buffer[j] = (add % 10) + '0';
	}
	if (addrem)
		return (0);
	return (1);
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
	int i, j, k, r = 1, size_1, size_2, tot_size;
	char *buffer;
	char msg[] = "Error\n";

	if (argc != 3 || check(argc, argv))
	{
		for (j = 0; msg[j]; j++)
			_putchar(msg[j]);
		exit(98);
	}
	for (size_1 = 0; argv[1][size_1]; size_1++)
		;
	for (size_2 = 0; argv[2][size_2]; size_2++)
		;
	tot_size = size_1 + size_2 + 1;
	buffer = malloc(tot_size * sizeof(char));
	if (buffer == NULL)
	{
		for (j = 0; msg[j]; j++)
			_putchar(msg[j]);
		exit(98);
	}
	init(buffer, tot_size - 1);
	for (k = size_2 - 1, i = 0; k >= 0; k--, i++)
	{
		r = mult(buffer, tot_size - i, argv[1], size_1 - 1, argv[2][k]);
		if (r == 0)
		{
			for (j = 0; msg[j]; j++)
				_putchar(msg[j]);
			free(buffer);
			exit(98);
		}
	}
	print_msg(buffer, tot_size - 1);

	return (0);
}
