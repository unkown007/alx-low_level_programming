#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (sucess)
 */
int main(void)
{
	int i, j, k, l, min, aux;

	min = 48;
	aux = 1;
	for (i = 0; i <= 9; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			for (k = (i > 0 ? i : 0), l = (aux != 1 ? (j > 0 ? j + 1 : 0) : 1); k <= 9; k++)
			{
				for (; l <= 9; l++)
				{
					if ((i == k) && (j == l))
						continue;
					putchar(min + i);
					putchar(min + j);
					putchar(' ');
					putchar(min + k);
					putchar(min + l);
					if (i == 9 && l == 9 && j == 8)
						continue;
					putchar(',');
					putchar(' ');
				}
				l = 0;
				aux = 0;
			}
		}
	}
	putchar('\n');

	return (0);
}
