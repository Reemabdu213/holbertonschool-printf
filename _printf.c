#include "main.h"
#include <stdarg.h>

/**
 * print_char - prints a single character
 * @ap: argument list containing the character
 * Return: number of characters printed, -1 on error
 */
static int print_char(va_list ap)
{
	char c = (char)va_arg(ap, int);

	if (_putchar(c) == -1)
		return (-1);
	return (1);
}

/**
 * print_string - prints a string
 * @ap: argument list containing the string
 * Return: number of characters printed, -1 on error
 */
static int print_string(va_list ap)
{
	const char *s = va_arg(ap, char *);
	int count = 0;

	if (!s)
		s = "(null)";
	while (*s)
	{
		if (_putchar(*s) == -1)
			return (-1);
		s++;
		count++;
	}
	return (count);
}

/**
 * print_percent - prints a percent sign
 * Return: number of characters printed, -1 on error
 */
static int print_percent(void)
{
	if (_putchar('%') == -1)
		return (-1);
	return (1);
}

/**
 * handle_specifier - handles a single format specifier
 * @sp: format specifier character
 * @ap: argument list
 * Return: number of characters printed, -1 on error
 */
static int handle_specifier(char sp, va_list ap)
{
	if (sp == 'c')
		return (print_char(ap));
	else if (sp == 's')
		return (print_string(ap));
	else if (sp == '%')
		return (print_percent());

	if (_putchar('%') == -1)
		return (-1);
	if (_putchar(sp) == -1)
		return (-1);
	return (2);
}

/**
 * _printf - prints output according to a format
 * @format: format string containing directives
 * Description: handles %c, %s, and %% conversion specifiers.
 * Return: number of characters printed (excluding null byte), -1 on error
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, total = 0, added = 0;

	if (!format)
		return (-1);

	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			if (_putchar(format[i]) == -1)
			{
				va_end(ap);
				return (-1);
			}
			total++;
			i++;
			continue;
		}
		i++;
		if (!format[i])
		{
			va_end(ap);
			return (-1);
		}
		added = handle_specifier(format[i], ap);
		if (added == -1)
		{
			va_end(ap);
			return (-1);
		}
		total += added;
		i++;
	}
	va_end(ap);
	return (total);
