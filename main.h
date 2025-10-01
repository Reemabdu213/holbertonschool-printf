#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_normal_char(char c);
int handle_specifier(char specifier, va_list args);
int print_string(char *str);
int print_number(int n);
int _putchar(char c);

#endif
