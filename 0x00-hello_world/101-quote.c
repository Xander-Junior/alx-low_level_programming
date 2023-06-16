#include <unistd.h>

/**
 * main - Entry point
 *
 * Description: Prints a quote to the standard error
 *
 * Return: Always 1 (Error)
 */
int main(void)
{
    char *q = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";

    write(2, q, 59);

    return (1);
}
