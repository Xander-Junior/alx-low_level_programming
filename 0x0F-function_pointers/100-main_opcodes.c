#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the opcodes of its own main function.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 *
 * Return: Always 0 (success).
 */
int main(int argc, char *argv[])
{

	int bytes, i;
	unsigned char *ptr_to_main = (unsigned char *)main;

	if (argc != 2)
	{
		printf("Error\n");
		 exit(1);
	}

	bytes = atoi(argv[1]);

	if (bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	for (i = 0; i < bytes - 1; i++)
		printf("%02x ", ptr_to_main[i]);

	printf("%02x\n", ptr_to_main[i]);

	return (0);
}
