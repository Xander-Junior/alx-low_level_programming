#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <stdio.h>

/* Function prototypes */
int _putchar(char c);
char *_strchr(char *s, char c);
unsigned int _strspn(char *s, char *accept);
char *_strpbrk(char *s, char *accept);
char *_strstr(char *haystack, char *needle);
void print_chessboard(char (*a)[8]);
void set_string(char **s, char *to);

/* Any other declarations or macro definitions */

#endif /* MAIN_H */

