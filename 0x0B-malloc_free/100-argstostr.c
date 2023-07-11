#include "main.h"
#include <stdlib.h>

/**
 * argstostr - Concatenates all the arguments of the program.
 * @ac: The argument count.
 * @av: The argument vector.
 *
 * Return: Pointer to the new concatenated string,
 *         or NULL on failure.
 */
char *argstostr(int ac, char **av)
{
	char *str;
	int total_length = 0, i, j, k = 0;

	if (ac == 0 || av == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			total_length++;
		}
	}

	total_length += ac - 1;

	str = malloc(sizeof(char) * (total_length + 1));
	if (str == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++, k++)
		{
			str[k] = av[i][j];
		}
		if (i != ac - 1)
		{
			str[k++] = '\n';
		}
	}

	str[k] = '\0';

	return (str);
}
