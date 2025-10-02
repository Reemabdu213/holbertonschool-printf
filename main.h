#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);

/* Advanced: binary support */
int print_binary(unsigned int n);
/* Advanced specifiers (u, o, x, X, b) */
int print_uint(unsigned int n);
int print_octal(unsigned int n);
int print_hex_low(unsigned int n);
int print_hex_up(unsigned int n);
int print_unsigned_base(unsigned int n, unsigned int base, int uppercase);

#endif /* MAIN_H */
