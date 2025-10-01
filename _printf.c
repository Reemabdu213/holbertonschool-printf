#include "main.h"

/**
 * handle_specifier - checks and executes matching format specifier
 * @c: specifier character
 * @ap: argument list
 * Return: number of characters printed
 */
int handle_specifier(char c, va_list ap)
{
	int k = 0;
	spec_t table[] = {
		{'c', print_char}, {'s', print_string},
		{'%', print_percent}, {'d', print_int},
		{'i', print_int}, {'\0', NULL}
	};

	while (table[k].sp)
	{
		if (table[k].sp == c)
			return (table[k].func(ap));
		k++;
	}
	_putchar('%');
	_putchar(c);
	return (2);
}

/**
 * _printf - produces output according to a format
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0;
	int count = 0;

	if (!format)
		return (-1);

	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			count += _putchar(format[i]);
			i++;
			continue;
		}
		i++;
		if (!format[i])
		{
			va_end(ap);
			return (-1);
		}
		count += handle_specifier(format[i], ap);
		i++;
	}
	va_end(ap);
	return (count);
}
