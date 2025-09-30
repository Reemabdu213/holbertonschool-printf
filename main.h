#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct fmt_spec - specifier/function pair
 * @sym: specifier character
 * @fn:  function that prints this specifier
 */
typedef struct fmt_spec
{
    char sym;
    int (*fn)(va_list);
} fmt_t;

int _putchar(char c);
int _printf(const char *format, ...);

/* Printers */
int print_char(va_list ap);
int print_string(va_list ap);
int print_percent(va_list ap);

/* Helpers */
int print_cstring(const char *s);

#endif /* MAIN_H */
