/* 
 * File: my_custom_lib.c
 * Desc: Custom library to override certain functions for educational purposes.
 *       This is a hypothetical scenario for learning about dynamic linking.
 */

int rand()
{
	static int counter = -1;
	int winning_numbers[] = {9, 8, 10, 24, 75, 9};
	counter++;
	return (winning_numbers[counter % 6]);
}
