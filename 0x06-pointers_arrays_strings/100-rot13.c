#include "main.h"

/**
 * rot13 - Encodes a string using ROT13 cipher.
 *
 * @str: Pointer to the string to be encoded.
 *
 * Return: Pointer to the encoded string.
 */
char *rot13(char *str)
{
	char *ptr = str;
	int i;

	while (*ptr)
	{
		for (i = 0; (*ptr >= 'A' && *ptr <= 'Z') || (*ptr >= 'a' && *ptr <= 'z'); i++)
		{
			if ((*ptr >= 'A' && *ptr <= 'M') || (*ptr >= 'a' && *ptr <= 'm'))
			{
				*ptr += 13;
			}
			else
			{
				*ptr -= 13;
			}
			ptr++;
		}
		ptr++;
	}

	return (str);
}
