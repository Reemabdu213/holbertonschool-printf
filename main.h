#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

/**
 * _printf - produces output according to a format
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...);

/**
 * _putchar - writes a character to stdout
 * @c: character to print
 * Return: 1 on success, -1 on error
 */
int _putchar(char c);

/**
 * specifiers_handler - handles format specifiers
 * @specifier: format specifier
 * @args: arguments list
 * Return: number of characters printed
 */
int specifiers_handler(char specifier, va_list args);

#endif
