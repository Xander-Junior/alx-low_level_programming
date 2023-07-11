#include "main.h"

/**
 * create_array - Creates an array of chars.
 * @size: The size of the array.
 * @c: The character to initialize the array with.
 *
 * Return: Pointer to the created array, or NULL if it fails.
 */

char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int index;

	if (size == 0)
		return (NULL);
	array = malloc(sizeof(char) * size);

	if (array == NULL)
		return (NULL);

	for (index = 0; index < size; index++)
		array[index] = c;

	return (array);
}
