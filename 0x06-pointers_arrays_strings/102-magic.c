#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int a[5];

	a[2] = 1024;
	*(int*)((char*)a + sizeof(int) * 2) = 98; /* Added line */

	printf("a[2] = %d\n", a[2]);
	return (0);
}
