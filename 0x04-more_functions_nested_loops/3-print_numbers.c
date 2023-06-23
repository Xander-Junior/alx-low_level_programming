#include "main.h"

/**
 * print_numbers - Prints the numbers from 0 to 9
 */
void print_numbers(void)
{
	int i;

	for (i = 0; i <= 9; i++)
	{
		_putchar(i + '0'); /* Convert the integer to character and print */
	}

	_putchar('\n'); /* Print a new line */
}
