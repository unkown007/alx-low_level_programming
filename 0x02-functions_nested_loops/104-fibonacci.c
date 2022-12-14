#include <stdio.h>
#include <gmp.h>

/**
 * fibonacci - computes and print the first 98 Fibonacci numbers
 */
void fibonacci(void)
{
	mpz_t a1, a2, an;
	int count;

	count = 2;

	mpz_init(a1);
	mpz_init(a2);
	mpz_init(an);

	mpz_set_ui(a1, 1);
	mpz_set_ui(a2, 2);
	mpz_set_ui(an, 0);

	mpz_out_str(stdout, 10, a1);
	printf(", ");
	mpz_out_str(stdout, 10, a2);
	printf(", ");

	while (count < 98)
	{
		mpz_add(an, a2, a1);
		mpz_set(a1, a2);
		mpz_set(a2, an);

		mpz_out_str(stdout, 10, an);

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
