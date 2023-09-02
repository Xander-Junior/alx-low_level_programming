#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number, or 0 if
 * - there is one or more chars in the string b that is not 0 or 1
 * - b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int number = 0;

	if (!b)
	{
		return (0);
	}

	while (*b)
	{
		if (*b == '1')
			number = (number << 1) | 1;
		else if (*b == '0')
			number <<= 1;
		else
			return (0);
		b++;
	}
	return (number);
}
