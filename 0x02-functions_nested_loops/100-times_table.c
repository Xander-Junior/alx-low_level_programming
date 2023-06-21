#include "main.h"

/**
 * print_times_table - Prints the n times table
 * @n: The number to print the times table for
 */
void print_times_table(int n)
{
	int i, j, result;

	if (n < 0 || n > 15)
		return;

	for (i = 0; i <= n; i++)
	{
		_putchar('0');
		_putchar(',');
		_putchar(' ');

		for (j = 1; j <= n; j++)
		{
			result = i * j;

			if (result < 10)
			{
				_putchar(' ');
				_putchar(' ');
			}
			else if (result < 100)
			{
				_putchar(' ');
			}

			_putchar(result / 100 + '0');
			_putchar((result / 10) % 10 + '0');
			_putchar(result % 10 + '0');
			
			if (j < n )
			{
				_putchar(',');
				_putchar(' ');
			}
		}

			_putchar('\n');
		}
}
