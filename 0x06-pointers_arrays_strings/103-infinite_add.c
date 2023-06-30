#include "main.h"
#include <stdio.h>

/**
 * infinite_add - Adds two numbers
 * @n1: The first number
 * @n2: The second number
 * @r: The buffer to store the result
 * @size_r: The size of the buffer
 *
 * Return: Pointer to the result
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i, j, k, len1, len2, carry, sum;

	len1 = 0;
	while (n1[len1] != '\0')
	{
		len1++;
	}
	len2 = 0;
	while (n2[len2] != '\0')
	{
		len2++;
	}
	if (len1 >= size_r || len2 >= size_r)
	{
		return (0);
	}

	carry = 0;
	i = len1 - 1;
	j = len2 - 1;
	k = size_r - 1;
	r[k] = '\0';
	while (i >= 0 || j >= 0)
	{
		sum = carry;
		if (i >= 0)
		{
			sum += n1[i] - '0';
		}
		if (j >= 0)
		{
			sum += n2[j] - '0';
		}
		carry = sum / 10;
		r[--k] = sum % 10 + '0';
		i--;
		j--;
	}
	if (carry > 0 && k > 0)
	{
		r[--k] = carry + '0';
		return (r + k);
	}
	if (carry == 0)
	{
		return (r + k + 1);
	}
	return (0);
}
