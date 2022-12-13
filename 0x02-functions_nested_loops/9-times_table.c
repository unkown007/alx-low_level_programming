#include "main.h"

/**
 * times_table - prints the 9 times table, starting with 0
 */
void times_table(void)
{
	int i, j, n;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			n = j * i;
			if (n > 9)
			{
				_putchar((n / 10) + '0');
				_putchar((n % 10) + '0');
			} else
				_putchar(n + '0');

			if (j < 9)
			{
				_putchar(',');
				if ((i * (j + 1)) <= 9)
				{
					_putchar(' ');
					_putchar(' ');
				} else
					_putchar(' ');
			}
		}
		_putchar('\n');
	}
}
