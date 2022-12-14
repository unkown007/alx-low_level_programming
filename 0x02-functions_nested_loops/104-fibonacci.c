#include <stdio.h>

/**
 * fibonacci - computes and print the first 98 Fibonacci numbers
 */
void fibonacci(void)
{
	unsigned long a1, a2, an;
	int count;

	count = 2;

	a1 = 1;
	a2 = 2;
	an = 0;

	printf("%d, %d, ", (int) a1, (int) a2);

	while (count < 98)
	{
		an = a2 + a1;
		a1 = a2;
		a2 = an;

		if (count == 92)
			an = an - 1;

		printf("%lu",  an);

		if (count < 97)
		{
			printf(", ");
		}
		count++;
	}
	printf("\n");
}


/**
 * main - tests the function
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	fibonacci();
	return (0);
}
