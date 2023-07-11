#include "main.h"
#include <stdlib.h>

/**
 * str_concat - Concatenates two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: Pointer to the newly allocated concatenated string,
 *         or NULL on failure.
 */
char *str_concat(char *s1, char *s2)
{
	char *concat_str;
	int index, concat_index = 0, len = 0;

	if (s1 == NULL)
	{
		s1 = "";
	}

	if (s2 == NULL)
	{
		s2 = "";
	}

	for (index = 0; s1[index] || s2[index]; index++)
	{
		len++;
	}

	concat_str = malloc(sizeof(char) * (len + 1));

	if (concat_str == NULL)
	{
		return (NULL);
	}

	for (index = 0; s1[index]; index++)
	{
		concat_str[concat_index++] = s1[index];
	}

	for (index = 0; s2[index]; index++)
	{
		concat_str[concat_index++] = s2[index];
	}

	concat_str[concat_index] = '\0';

	return (concat_str);
}
