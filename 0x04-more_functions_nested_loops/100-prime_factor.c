#include <stdio.h>
/**
* bigprime - biggest prime number
* @n: int arg
* Return: value prime-number largest
*/
int bigprime(unsigned long int n)
{
	long int i;

	for (i = 2; i <= n; i++)
	{
		if (n % i == 0)
			n = n / i;
		else
			continue;
	}
	return (i - 1);
}
/**
* main - entry point
* Return: 0
*/
int main(void)
{
	unsigned long int n = 612852475143;
	unsigned long int l = bigprime(n);

	printf("%ld\n", l);
	return (0);
}
