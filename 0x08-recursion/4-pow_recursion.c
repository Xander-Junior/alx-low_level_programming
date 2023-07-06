#include "main.h"

/**
 * _pow_recursion - Calculates the value of x raised to the power of y
 * @x: The base number
 * @y: The exponent
 *
 * Return: The result of x raised to the power of y
 */
int _pow_recursion(int x, int y)
{
	/* Base case: y is 0 */
	if (y == 0)
	{
		return (1);
	}

	/* Base case: y is negative */
	if (y < 0)
	{
		return (-1);
	}

	/* Recursive case: multiply x with _pow_recursion(x, y - 1) */
	return (x * _pow_recursion(x, y - 1));
}
