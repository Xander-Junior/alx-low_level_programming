#include <stdlib.h>
#include "dog.h"


/**
 * _strlen - Calculates the length of a string
 * @str: The input string
 *
 * Return: The length of the string
 */
int _strlen(char *str)
{
	int length = 0;

	while (*str != '\0')
	{
		length++;
		str++;
	}
	return (length);
}


/**
 * _strcopy - Copies a string to a destination buffer
 * @dest: The destination buffer
 * @src: The source string
 *
 * Return: Pointer to the destination buffer
 */
char *_strcopy(char *dest, char *src)
{
	char *ptr = dest;
	while (*src)
	{
		*ptr = *src;
		src++;
		ptr++;
	}
	*ptr = '\0';
	return (dest);
}




/**
 * new_dog - Creates a new dog
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Owner of the dog
 *
 * Return: Pointer to the newly created dog (dog_t)
 *         NULL if the function fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog;
	int name_length, owner_length;
	char *new_name, *new_owner;

	name_length = _strlen(name);
	owner_length = _strlen(owner);

	new_dog = malloc(sizeof(dog_t));
	if (new_dog == NULL)
		return NULL;

	new_name = malloc((name_length + 1) * sizeof(char));
	new_owner = malloc((owner_length + 1) * sizeof(char));
	if (new_name == NULL || new_owner == NULL)
	{
		free(new_dog);
		free(new_name);
		free(new_owner);
		return (NULL);
	}
	
	_strcopy(new_name, name);
	_strcopy(new_owner, owner);

	new_dog->name = new_name;
	new_dog->age = age;
	new_dog->owner = new_owner;

	return (new_dog);
}
