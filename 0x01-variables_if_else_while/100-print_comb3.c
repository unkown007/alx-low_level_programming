#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (sucess)
 */
int main(void)
{
	int i, j, tmp;

	tmp = 9;
	for (i = 48; i < 57; i++)
	{
		for (j = 1; j <= tmp; j++)
		{
			putchar(i);
			putchar(i + j);
			if (i < 56)
			{
				putchar(',');
				putchar(' ');
			}
		}
		tmp--;
	}
	putchar('\n');

	return (0);
}
