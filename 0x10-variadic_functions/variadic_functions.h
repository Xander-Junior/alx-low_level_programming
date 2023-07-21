#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h>
/**
 * struct print_type - Struct print_type
 *
 * @type: The format character
 * @printer: The corresponding print function
 */
typedef struct print_type
{
    char type;
    void (*printer)(va_list args);
} print_type_t;


int _putchar(char c);

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

#endif /* VARIADIC_FUNCTIONS_H */
