#include <stdio.h>
#include <math.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	unsigned long int n = 612852475143;
	unsigned long int i;

	for (i = 2; i <= sqrt(n); i++)
	{
		while (n % i == 0)
		{
			n = n / i;
		}
	}

	if (n > 2)
	{
		printf("%lu\n", n);
	}
	else
	{
		printf("%lu\n", i);
	}

	return (0);
}
