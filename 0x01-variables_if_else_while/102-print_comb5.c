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
		for (j = 0; j < 9; j++)
		{
			for (k = 0; k <= 9; k++)
			{
				for (l = (aux != 1 ? 0 : 1)/*(aux != 1 ? (i > 0 ? j + 1 : j) : 1)*/; l <= 9; l++)
				{
					putchar(min + i);
					putchar(min + j);
					putchar(' ');
					putchar(min + k);
					putchar(min + l);
					if (j <= 8)
					{
						putchar(',');
						putchar(' ');
					}
				}
				aux = 0;
			}
		}
	}
	putchar('\n');

	return (0);
}
