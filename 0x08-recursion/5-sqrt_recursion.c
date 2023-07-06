#include "main.h"

/**
 * sqrt_recursive - Calculates the square root using recursive approach
 * @n: The number to calculate the square root of
 * @i: The current value to check as the square root
 *
 * Return: The square root of n if it exists, -1 otherwise
 */
int sqrt_recursive(int n, int i)
{
	/* Base case: perfect square found */
	if (i * i == n)
	{
		return (i);
	}

	/* Base case: no square root found */
	if (i * i > n)
	{
		return (-1);
	}

	/* Recursive case: increment i and continue searching */
	return (sqrt_recursive(n, i + 1));
}

/**
 * _sqrt_recursion - Calculates the square root of a number
 * @n: The number to calculate the square root of
 *
 * Return: The square root of n if it exists, -1 otherwise
 */
int _sqrt_recursion(int n)
{
	/* Edge case: negative number */
	if (n < 0)
	{
		return (-1);
	}

	return (sqrt_recursive(n, 0));
}
