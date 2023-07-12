#include "main.h"
#include <stdlib.h>

/**
 * count_words - Counts the number of words in a string.
 * @str: The input string.
 *
 * Return: The number of words.
 */
int count_words(char *str)
{
	int count = 0, i = 0;

	while (str[i])
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
		{
			count++;
		}
		i++;
	}

	return (count);
}


/**
 * strtow - Splits a string into words.
 * @str: The input string.
 *
 * Return: Pointer to an array of strings (words), or NULL on failure.
 */
char **strtow(char *str)
{
	char **words;
	int i, j, k, len, count;

	if (str == NULL || *str == '\0')
	{
		return NULL;
	}

	count = count_words(str);

	words = malloc(sizeof(char *) * (count + 1));
	if (words == NULL)
	{
		return (NULL);
	}

	i = 0;
	j = 0;

	while (str[i])
	{
		if (str[i] != ' ')
		{
			len = 0;
			k = i;
			while (str[k] && str[k] != ' ')
			{
				len++;
				k++;
			}

			words[j] = malloc(sizeof(char) * (len + 1));
			if (words[j] == NULL)
			{
				for (i = 0; i < j; i++)
				{
					free(words[i]);
				}
				free(words);
				return (NULL);
			}

			k = 0;
			while (str[i] && str[i] != ' ')
			{
				words[j][k] = str[i];
				k++;
				i++;
			}
			words[j][k] = '\0';
			j++;
		}
		else
		{
			i++;
		}
	}
	words[j] = NULL;

	return (words);
}
