#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	char *num1;
	char *num2;
	char *result;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	num1 = argv[1];
	num2 = argv[2];

	if (!is_valid_number(num1) || !is_valid_number(num2))
	{
		printf("Error\n");
		return (98);
	}

	result = multiply_numbers(num1, num2);
	if (result == NULL)
	{
		printf("Error\n");
		return (98);
	}

	printf("%s\n", result);
	free(result);

	return (0);
}

/**
 * is_valid_number - Check if a string is a valid positive number
 * @str: The input string
 *
 * Return: 1 if valid, 0 otherwise
 */
int is_valid_number(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

/**
 * multiply_numbers - Multiply two positive numbers
 * @num1: The first number
 * @num2: The second number
 *
 * Return: The product as a string, or NULL on failure
 */
char *multiply_numbers(char *num1, char *num2)
{
	int len1, len2, result_len;
	int *result;
	int i, j, carry, digit1, digit2, product;
	int start;
	char *product_str;

	len1 = _strlen(num1);
	len2 = _strlen(num2);
	result_len = len1 + len2;
	result = _calloc(result_len, sizeof(int));

	if (result == NULL)
		return (NULL);
	for (i = len1 - 1; i >= 0; i--)
		carry = 0;
		digit1 = num1[i] - '0';

		for (j = len2 - 1; j >= 0; j--)
			digit2 = num2[j] - '0';
			product = digit1 * digit2 + result[i + j + 1] + carry;
			result[i + j + 1] = product % 10;
			carry = product / 10;
		if (carry > 0)
			result[i + j + 1] += carry;
	start = 0;
	while (start < result_len && result[start] == 0)
		start++;
	if (start == result_len)
		start--;
	product_str = malloc(result_len - start + 1);

	if (product_str == NULL)
		free(result);
		return (NULL);
	for (i = 0; i < result_len - start; i++)
		product_str[i] = result[start + i] + '0';
	product_str[i] = '\0';
	free(result);
	return (product_str);
}

/**
 * _strlen - Calculate the length of a string
 * @str: The input string
 *
 * Return: The length of the string
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}


/**
 * _calloc - Allocate memory for an array and set all elements to 0
 * @nmemb: Number of elements
 * @size: Size of each element
 *
 * Return: A pointer to the allocated memory, or NULL on failure
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	void *ptr = malloc(nmemb * size);
	char *p;

	if (ptr == NULL)
		return (NULL);

	p = ptr;
	for (i = 0; i < nmemb * size; i++)
		p[i] = 0;

	return (ptr);
}
