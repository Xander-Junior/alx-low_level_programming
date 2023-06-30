#include "main.h"

/**
 * print_cell - Prints a single cell of the times table
 * @value: The value to print
 * @is_first: Flag indicating if it's the first cell in the row
 */
void print_cell(int value, int is_first)
{
    if (!is_first)
    {
        _putchar(',');
        _putchar(' ');

        if (value < 10)
        {
            _putchar(' ');
            _putchar(' ');
            _putchar(value + '0');
        }
        else if (value < 100)
        {
            _putchar(' ');
            _putchar(value / 10 + '0');
            _putchar(value % 10 + '0');
        }
        else
        {
            _putchar(value / 100 + '0');
            _putchar((value / 10) % 10 + '0');
            _putchar(value % 10 + '0');
        }
    }
    else
    {
        _putchar(value + '0');
    }
}
