#include "main.h"

/**
 * jack_bauer - prints every minute of the day starting from 00:00 to 23:59
 *
 */
void jack_bauer(void)
{
	int i, j, k, l, tmp;

	for (i = 0; i <= 2; i++)
	{
		tmp = ((i < 2) ? 9 : 3);
		for (j = 0; j <= tmp; j++)
		{
			for (k = 0; k <= 5; k++)
			{
				for (l = 0; l <= 9; l++)
				{
					_putchar(i + '0');
					_putchar(j + '0');
					_putchar(':');
					_putchar(k + '0');
					_putchar(l + '0');
					_putchar('\n');
				}
			}
		}
	}
}
