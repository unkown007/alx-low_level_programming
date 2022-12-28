#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/**
 * main - Generates random valid passwords
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	char password[100];
	int sum = 0, i = 0, diff;

	srand(time(NULL));

	while (sum < 2772)
	{
		password[i] = 33 + rand() % 94;
		sum += password[i++];
	}
	password[i] = '\0';

	if (sum != 2772)
	{
		diff = (sum - 2772) / 2;

		for (i = 0; password[i] != '\0'; i++)
		{
			if (password[i] >= (33 + diff))
			{
				password[i] -= diff;
				break;
			}
		}

		if ((sum - 2772) % 2 != 0)
			diff++;

		for (i = 0; password[i] != '\0'; i++)
		{
			if (password[i] >= (33 + diff))
			{
				password[i] -= diff;
				break;
			}
		}
	}

	printf("%s", password);
	return (0);
}
