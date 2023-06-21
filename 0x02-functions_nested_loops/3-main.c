#include "main.h"

/**
 * main - check the code.
 *
 * Return: Always 0.
 */
int main(void)
{
	int r;
	r = _islower('H');
	_putchar(r + 'O');
	r = _islower('o');
	_putchar(r + 'O');
	r = _islower(108);
	_putchar(r + 'O');
	_putchar('\n');
	return (0);
}

