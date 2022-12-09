#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (sucess)
 */
int main(void)
{
	int i, j, k, tmp, tmp1;

	tmp = 9;
	tmp1 = 8;
	for (i = 48; i < 56; i++)
	{
		for (j = 1; j <= tmp1; j++)
		{
			for (k = 1 + j; k <= tmp; k++)
			{
				putchar(i);
				putchar(i + j);
				putchar(i + k);
				if (i < 55)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
		tmp1--;
		tmp--;
	}
	putchar('\n');

	return (0);
}
