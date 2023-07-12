#include "main.h"
#include <stdlib.h>

/**
 * strtow - Splits a string into words.
 * @str: The input string.
 *
 * Return: Pointer to an array of strings (words), or NULL on failure.
 */
char **strtow(char *str)
{
	int words = 0, i = 0, j = 0, temp = 0, size = 0;
	char **split = NULL;

	if (str == NULL || *str == '\0')
	{
		return (NULL);
	}

	words = num_words(str);
	if (words == 0)
	{
		return (NULL);
	}

	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (split == NULL)
	{
		return (NULL);
	}

	for (i = 0; str[i] != '\0' && j < words; i++)
	{
		if (str[i] != ' ')
		{
			size++;
		}
		else if (str[i] == ' ' && size > 0)
		{
			split[j] = (char *)malloc(sizeof(char) * (size + 1));
			if (split[j] == NULL)
			{
				for (j = 0; j < i; j++)
				{
					free(split[j]);
				}
				free(split);
				return (NULL);
			}
			for (temp = 0; temp < size; temp++)
			{
				split[j][temp] = str[i - size + temp];
			}
			split[j][temp] = '\0';
			size = 0;
			j++;
		}
	}

	split[j] = NULL;
	return (NULL);
}

/**
 * num_words - Counts the number of words in a string.
 * @str: The input string.
 *
 * Return: The number of words.
 */
int num_words(char *str)
{
	int i = 0, words = 0;

	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			words++;
			while (str[i] != ' ' && str[i] != '\0')
			{
				i++;
			}
		}
		else
		{
			i++;
		}
	}

	return (words);
}


/**
 * len - Returns the length of a string.
 * @str: The input string.
 *
 * Return: The length of the string.
 */
int len(char *str)
{
	int length = 0;

	if (str != NULL)
	{
		while (str[length] != '\0')
		{
			length++;
		}
	}

	return (length);
}
