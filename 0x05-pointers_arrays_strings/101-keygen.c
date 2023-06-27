#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int sum = 2772;
	int rand_num;
	char c;

	srand(time(0));

	while (sum > 122)
	{
		rand_num = rand() % 100;
		c = rand_num;
		printf("%c", c);
		sum -= rand_num;
	}
	
	printf("%c", sum);

	return (0);
}
