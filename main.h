#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * struct specifier - Struct for specifier and function
 * @sp: format specifier
 * @func: function pointer to handler
 */
typedef struct specifier
{
	char sp;
	int (*func)(va_list);
} spec_t;

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list ap);
int print_string(va_list ap);
int print_percent(va_list ap);
int print_int(va_list ap);

#endif
