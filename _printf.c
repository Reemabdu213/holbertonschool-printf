#include "main.h"
#include <stdarg.h>

/* Prototypes */
int print_normal_char(char c);
int handle_specifier(char specifier, va_list args);
int print_string(char *str);
int print_number(int n);

/**
 * _printf - Prints a formatted string
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format)
				printed += handle_specifier(*format, args);
		}
		else
		{
			printed += print_normal_char(*format);
		}
		format++;
	}

	va_end(args);
	return (printed);
}

/**
 * print_normal_char - Prints a single character
 * @c: Character to print
 *
 * Return: Number of characters printed (1)
 */
int print_normal_char(char c)
{
	_putchar(c);
	return (1);
}

/**
 * handle_specifier - Handles format specifiers
 * @specifier: Format specifier character
 * @args: Argument list
 *
 * Return: Number of characters printed
 */
int handle_specifier(char specifier, va_list args)
{
	int count = 0;

	switch (specifier)
	{
		case 'c':
			count += print_normal_char(va_arg(args, int));
			break;
		case 's':
			count += print_string(va_arg(args, char *));
			break;
		case 'd':
		case 'i':
			count += print_number(va_arg(args, int));
			break;
		case '%':
			count += print_normal_char('%');
			break;
		default:
			count += print_normal_char('%');
			count += print_normal_char(specifier);
			break;
	}

	return (count);
}
