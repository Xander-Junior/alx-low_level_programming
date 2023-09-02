#include "main.h"
#include <stdio.h>

/**
 * print_binary - prints the binary representation of a number
 * @n: number to print in binary
 */
void print_binary(unsigned long int n)
{
	int i;
	int print_flag = 0;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	
	for (i = (sizeof(n) * 8) - 1; i >= 0; i--)
	{
		if (n & (1UL << i))
		{
			_putchar('1');
			print_flag = 1;
		}
		else if (print_flag)
		{
			_putchar('0');
		}
	}
}
