#ifndef MAIN_H

#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);

/* Advanced: binary support */
int print_binary(unsigned int n);

/* Unsigned helpers */
int print_unsigned(unsigned int n);
int print_octal(unsigned int n);
int print_hex(unsigned int n, int uppercase);

#endif /* MAIN_H */
