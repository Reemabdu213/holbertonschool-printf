#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* core */
int _printf(const char *format, ...);
int _putchar(char c);

/* specifier handlers */
int print_char(va_list ap);
int print_string(va_list ap);
int print_percent(va_list ap);
int print_unsigned(unsigned int n);

/* helpers */
int print_normal_char(char c);
int handle_specifier(char c, va_list ap);

#endif
