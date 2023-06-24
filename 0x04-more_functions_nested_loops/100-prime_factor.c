#include <stdio.h>
#include <math.h>

/**
 * largest_prime_factor - finds the largest prime factor of a number
 * @n: the number to find the largest prime factor of
 *
 * Return: the largest prime factor of the number
 */
long largest_prime_factor(long n)
{
    long i;

    for (i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
        }
    }

    if (n > 1)
        return n;
    else
        return i;
}
