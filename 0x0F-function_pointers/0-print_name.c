#include <stdio.h>
#include "function_pointers.h"

/**
 * print_name - prints a name using a given printing function
 * @name: name to be printed
 * @f: pointer to the printing function to be used
 *
 * Return: Nothing
 */
void print_name(char *name, void (*f)(char *))
{
	if (name && f)
		f(name);
}
